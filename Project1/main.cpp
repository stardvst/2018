#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <iterator>

class Node
{
public:
	virtual ~Node() = default;

	const double getValue() const { return m_value;	}

protected:
	Node(double value) : m_value(value) {}

private:
	const double m_value;
};

class InternalNode : public Node
{
public:
	InternalNode(Node* left, Node* right) 
		: Node(left->getValue() + right->getValue())
		, m_left_ptr(left)
		, m_right_ptr(right)
	{
	}

	virtual ~InternalNode() override
	{
		delete m_left_ptr;
		delete m_right_ptr;
	}

	Node* getLeft() const { return m_left_ptr; }
	Node* getRight() const { return m_right_ptr; }

private:
	Node *m_left_ptr;
	Node *m_right_ptr;
};

class LeafNode : public Node
{
public:
	LeafNode(double value, char letter) : Node(value), m_letter(letter) {}
	
	const char getLetter() const { return m_letter; }

private:
	char m_letter;
};

class Less
{
public:
	bool operator()(Node* left, Node* right)
	{
		return left->getValue() < right->getValue();
	}
};

Node* buildTree(const std::vector<double> &frequencies)
{
	std::priority_queue<Node *, std::vector<Node *>, Less> heap;
	
	for (int i = 0; i < 256; ++i)
	{
		if (frequencies[i] != 0)
			heap.push(new LeafNode(frequencies[i], (char)i));
	}

	while (heap.size() > 1)
	{
		Node* left_child = heap.top();
		heap.pop();
		Node* right_child = heap.top();
		heap.pop();
		Node* parent = new InternalNode(left_child, right_child);
		heap.push(parent);
	}
	return heap.top();
}

using Code = std::vector<bool>;
using CodeMap = std::map<char, Code>;

void generateCode(Node* tree, CodeMap& code_map, Code prefix)
{
	if (auto node = dynamic_cast<LeafNode *>(tree))
	{
		code_map[node->getLetter()] = prefix;
	}
	else if (auto n = dynamic_cast<InternalNode *>(tree))
	{
		Code left_code = prefix;
		left_code.push_back(false);
		generateCode(n->getLeft(), code_map, left_code);
		Code right_code = prefix;
		right_code.push_back(true);
		generateCode(n->getRight(), code_map, right_code);
	}
}

int main()
{
	const int UniqueSymbols = 256;
	const char* SampleString = "Ani Harutyunyan added main function and fixed some minor buges";

	std::vector<double>	frequencies(UniqueSymbols, 0);

	while (*SampleString != '\0')
		++frequencies[*SampleString++];

	Node* root = buildTree(frequencies);

	CodeMap codes;
	generateCode(root, codes, Code());
	delete root;

	for (CodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it)
	{
		std::cout << it->first << " ";
		std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<bool>(std::cout));
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}