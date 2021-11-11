#pragma once
// Name: prof Q
// Date: 11-3-2021
// Description: binary tree node for growing a tree

#include <iostream>
#include <string>
using namespace std;

template <class Item>
class binary_tree_node
{
private:
    Item data;
    binary_tree_node* left;
    binary_tree_node* right;

public:

    //constructor
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
        data = init_data;
        left = init_left;
        right = init_right;
    }


    //PreCondition: NA
    //PostCondition: return value of the node    
    Item& getData()
    {
        return data;
    }

    //PreCondition: NA
    //PostCondition: return left node
    binary_tree_node*& getLeft()
    {
        return left;
    }

    //PreCondition: NA
    //PostCondition: return right node
    binary_tree_node*& getRight()
    {
        return right;
    }

    //PreCondition: NA
    //PostCondition: set data for the node
    void setData(const Item& new_data)
    {
        data = new_data;
    }

    //PreCondition: NA
    //PostCondition: set left node
    void setLeft(binary_tree_node* new_left)
    {
        left = new_left;
    }

    //PreCondition: NA
    //PostCondition: set right node
    void setRight(binary_tree_node* new_right)
    {
        right = new_right;
    }

    //PreCondition: NA
    //PostCondition: return value of the node
    const Item& getData() const
    {
        return data;
    }

    //PreCondition: NA
    //PostCondition: return left node
    const binary_tree_node* getLeft() const
    {
        return left;
    }

    //PreCondition: NA
    //PostCondition: return right node
    const binary_tree_node* getRight() const
    {
        return right;
    }

    //PreCondition: NA
    //PostCondition: return true if the node is a leaf node, otherwise return false
    bool isLeaf() const
    {
        return (left == NULL && right == NULL);
    }

};

//PreCondition: input binary tree node
//PostCondition: delete the tree using recurive
template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) // Recursive
{
    if (leaf == NULL)
        return;

    /* first delete both subtrees */
    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());

    /* then delete the node */
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;

}

//PreCondition: input prefix(string), binary tree node, isLeft, root and last
//PostCondition: displays the tree on the screen

template<class Item>
void print_tree(const string& prefix, const binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
    if (node != NULL)
    {
        cout << prefix;
        if (!root)
        {
            if (isLeft)
            {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            else
            {
                if (last)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';


        // enter the next tree level - left and right branch
        string s = "    ";
        s[0] = char(179);
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false,true);
    }
}