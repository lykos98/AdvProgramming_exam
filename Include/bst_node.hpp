#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <utility>
#include <exception>
#define KEY KV.first
#define VAL KV.second


template <typename KEY_type, typename VAL_type>
struct node
    {
        /*
        * struct node that contains a pair - Key value
        * pointer to left, right and parent nodes
        * constructors defined       
        */
        using pair_type = std::pair<KEY_type,VAL_type>;
        pair_type KV;
        std::unique_ptr<node> LEFT_child;
        std::unique_ptr<node> RIGHT_child;
        node* parent;
        
        node(const pair_type KV_init): KV{KV_init} {
            this->LEFT_child.reset(nullptr);
            this->RIGHT_child.reset(nullptr);
            this->parent = nullptr;
        };
        node(const node &node_to_copy_from) {
            this->LEFT_child.reset(nullptr);
            this->RIGHT_child.reset(nullptr);
            parent = nullptr;
            KV = node_to_copy_from.KV;
        }
        node& operator=(const node& node_to_copy_from){
            return *(new node(node_to_copy_from));
            }

        void _print_extended(){
            std::cout << "Node " << this << "\tLCH " << LEFT_child << "\tRCH " << RIGHT_child << "\tKV " << KEY << "  " << VAL << std::endl;
        }


        
        ~node(){};

        node(node &&) = default;
        node &operator=(node &&) = default;
        
        node* get_parent(){
            return parent;
        }

        KEY_type get_key(){
            return KV.first;
        }

        pair_type& get_pair(){
            return KV;
        }

        void set_parent(node* other_node){
            parent = other_node;
        }
        

        node* get_left(){
            return LEFT_child.get();
        }

        void set_left(node* other_node){
            LEFT_child.reset(other_node);
            other_node -> set_parent(this);
        }

        node* get_right(){
            return RIGHT_child.get();
        }

        void set_right(node* other_node){
            RIGHT_child.reset(other_node);
            other_node -> set_parent(this);
        }

        
        };
        
    
