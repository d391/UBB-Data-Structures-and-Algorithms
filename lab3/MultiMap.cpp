#include "MultiMap.h"


MainNode::MainNode()
{
}

MainNode::~MainNode()
{
	delete this->sideHead;
}

SideNode::SideNode()
{
	
}

SideNode::~SideNode()
{

}

//constructor 
//complexity: Theta(1)
MultiMap::MultiMap()
{
	this->head = NULL;
	this->mmSize = 0;
}

//adds a new element to the MultiMap
//complexity: O(n) n- number of total values
void MultiMap::add(TKey c, TValue v)
{
	if (this->head == NULL)
	{
		this->head = new MainNode;
		this->head->next = NULL;
		this->head->key = c;
		this->head->sideHead = new SideNode;
		this->head->sideHead->info = v;
		this->head->sideHead->next = NULL;
	}
	else
	{
		MainNode *main = new MainNode;
		main = this->head;
		while (main->next != NULL && main->key != c)
			main = main->next;
		if (main->key == c)
		{
			SideNode *side = new SideNode;
			side = main->sideHead;
			while (side->next != NULL)
				side = side->next;
			SideNode *newSide = new SideNode;
			newSide->next = NULL;
			newSide->info = v;
			side->next = newSide;
		}
		else
		{
			MainNode *newMain = new MainNode;
			newMain->key = c;
			newMain->next = NULL;
			newMain->sideHead = new SideNode;
			newMain->sideHead->info = v;
			newMain->sideHead->next = NULL;
			main->next = newMain;
		}
	}
	this->mmSize++;
}

//removes an element from the MultiMap
//return true if the element has been removed, false otherwise
//complexity: O(n) n- the size of the sll
bool MultiMap::remove(TKey c, TValue v)
{
	bool specialDelete = false;
	if (this->head != NULL)
	{
		MainNode *main = new MainNode;
		main = this->head;
		if (main->next == NULL && this->head->key == c)
		{
			SideNode *side = new SideNode;
			side = main->sideHead;
			if (side->info == v)
			{
				specialDelete = true;
				main->sideHead = main->sideHead->next;
				side->next = NULL;
				this->mmSize--;
				delete side;
			}
			else
			{
				while (side->next != NULL && side->info != v)
					side = side->next;
				if (side->info == v)
				{
					SideNode *prevSide = new SideNode, *nextSide = new SideNode;
					nextSide = side->next;
					prevSide = main->sideHead;
					while (prevSide->next != side)
						prevSide = prevSide->next;
					prevSide->next = nextSide;
					this->mmSize--;
					delete side;
					return true;
				}
			}
			if (this->head->sideHead == NULL)
			{
				this->head = NULL;
				return true;
			}
			if (specialDelete)
				return true;
		}
		while (main != NULL)
		{
			if (main->key == c)
			{
				SideNode *side = new SideNode;
				side = main->sideHead;
				if (side->info == v)
				{
					specialDelete = true;
					main->sideHead = main->sideHead->next;
					side->next = NULL;
					this->mmSize--;
					delete side;
				}
				else
				{
					while (side->next != NULL && side->info != v)
						side = side->next;
					if (side->info == v)
					{
						specialDelete = true;
						SideNode *prevSide = new SideNode, *nextSide = new SideNode;
						nextSide = side->next;
						prevSide = main->sideHead;
						while (prevSide->next != side)
							prevSide = prevSide->next;
						prevSide->next = nextSide;
						this->mmSize--;
						delete side;
					}
				}
				if (main->sideHead == NULL)
				{
					if (main == this->head)
					{
						this->head = this->head->next;
						delete main;
						return true;
					}
					else
					{
						MainNode *prevMain = new MainNode, *nextMain = new MainNode;
						nextMain = main->next;
						prevMain = this->head;
						while (prevMain->next != main)
							prevMain = prevMain->next;
						prevMain->next = nextMain;
						delete main;
						return true;
					}
				}
				if (specialDelete == true)
					return true;
			}
			main = main->next;
		}
	}
	return false;
}

//returns a vector of elements of certain given key
//complexity: O(n) n- the size of the sll of the given key
vector<TValue> MultiMap::search(TKey c) const
{
	vector<TValue> vec;
	if (this->head != NULL)
	{
		MainNode *main = new MainNode;
		main = this->head;
		while (main->next != NULL && main->key != c)
			main = main->next;
		if (main->key == c)
		{
			SideNode *side = new SideNode;
			side = main->sideHead;
			while (side->next != NULL)
			{
				vec.push_back(side->info);
				side = side->next;
			}
			vec.push_back(side->info);
		}
	}
	
	return vec;
}

//returns the size of the MultiMap
//complexity: Theta(1)
int MultiMap::size() const
{
	return this->mmSize;
}

//verifies if the MultiMap is empty
//returns true if it is, false otherwise
//complexity: Theta(1)
bool MultiMap::isEmpty() const
{
	if (this->mmSize == 0)
		return true;
	return false;
}


//returns the iterator of the MultiMap
//complexity: Theta(1)
MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}

TKey MultiMap::minKey() const
{
	MainNode *main = new MainNode;
	main = this->head;
	if (main == NULL)
		return NULL_TKEY;
	TKey minKey = main->key;
	main = main->next;
	while (main != NULL)
	{
		if (main->key < minKey)
			minKey = main->key;
		main = main->next;
	}
	return minKey;
}

MultiMap::~MultiMap()
{
	
}
