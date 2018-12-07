//PREPEND BEGIN
#include <iostream>
#include <iomanip>

using namespace std;

class Node{
    private:
        unsigned int  n;
        unsigned int* link_length;
        unsigned int* node_distance;

    public:
//PREPEND END

//TEMPLATE BEGIN
        Node(){}
        Node(unsigned int n){
            // TODO
            this->n = n;
            link_length = new unsigned int[n];
            node_distance = new unsigned int[n];
        }
        ~Node(){
            // TODO
            link_length = NULL;
            node_distance = NULL;
        }
        void set_value(int* len){
            // TODO
            for (int i = 0;i < n; i++) {
                link_length[i] = len[i];
                node_distance[i] = len[i];
            }
        }
        void update(const unsigned int n, int dist){
            // TODO
            node_distance[n] = dist;
        }
//TEMPLATE END

//APPEND BEGIN
        const int get_link_len(const unsigned int n){
            return link_length[n];
        }

        const int get_node_dis(const unsigned int n){
            return node_distance[n];
        }
};

int main(){
    int n;
    cin >> n;
    Node* nodes = new Node[n];
    for(int i = 0 ; i < n ; ++i)
        nodes[i] = Node(n);

    for(int i = 0 ; i < n ; ++i){
        int* temp = new int[n];
        for(int j = 0 ; j < n ; ++j)
            cin >> temp[j];
        nodes[i].set_value(temp);
    }

    bool  unstable = true;
    while(unstable){
        unstable = false;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                for( int k = 0 ; k < n ; ++k ){
                    // take min
                    if(nodes[i].get_node_dis(j) > nodes[i].get_node_dis(k) + nodes[k].get_node_dis(j)){
                       nodes[i].update(j, nodes[i].get_node_dis(k) + nodes[k].get_node_dis(j));
                       unstable = true;
                    }
                }
            }
        }
    }

    // print
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j )
            cout << setw(6) << nodes[i].get_node_dis(j);
        cout << endl;
    }
    return 0;
}
//APPEND END
