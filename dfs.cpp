#include <iostream>
#include <array>
#include <stdarg.h>
#include <stack>

class node
{
    private:
        int m_node;
        int* m_arc;
        int m_arc_count;
        //방문했다면 1 아니면 0

    public:
        bool m_visit;
        node(int node = 0, int m_arc_count = 0, const int* arc = NULL);

        void useNode()
        {
            m_visit = true;
        };
        void user_print()
        {
            std::cout << "node: " << m_node << " arc: ";
            for (int i = 0; i < m_arc_count; i++)
            {
                std::cout << m_arc[i] << ", ";
            };

            std::cout << std::endl;
        };

        void vist()
        {
            if (m_visit == false)
            {
                m_visit = true;
                std::cout << "visit: " << m_node << std::endl;
            }
            else
            {
                std::cout << "이미 방문함" << std::endl;
            }        
        }

        bool isVisit()
        {
            return m_visit;
        }

        int getNode()
        {
            return m_node;
        }
        //아크의 개수를 반환
        int getArcCount()
        {
            return m_arc_count;
        }

        //해당 인덱스의 아크를 반환
        int getArc(int index)
        {
            if (index > m_arc_count) return NULL;
            return m_arc[index];
        }

        ~node(){
            delete[] m_arc;
        }
};

struct arr_node {
    int size;
    node* node_list;
};

void dfs(arr_node arr_node, int startNode);

//arr_node 배열에서가장
node* getNodePointer(arr_node graph, int nodeVal) {
    for (int i = 0; i < graph.size; i++)
    {
        if (graph.node_list[i].getNode() == nodeVal) return &(graph.node_list[i]);
    };
    return 0;
}

int main(int argc, char* argv[])
{
    
    //int arr[5] = ;
    // node<int, 5> mynode(5, std::begin({ 1, 2, 3, 4, 5 }));

    //mynode.user_print();
    arr_node graph;
    int nodeCount = 8;
    graph.node_list = new node[nodeCount]{
        //(노드, 아크개수, 아크)
        node(1, 2, std::begin({2, 3})),
        node(2, 3, std::begin({1, 4, 5})),
        node(3, 3, std::begin({1, 6 ,7})),
        node(4, 2, std::begin({2, 8})),
        node(5, 2, std::begin({2, 8})),
        node(6, 2, std::begin({3, 8})),
        node(7, 2, std::begin({3, 8})),
        node(8, 4, std::begin({4,5,6,7}))
    };
    graph.size = 8;
    //getNodePointer(graph, 1)->user_print();

    dfs(graph, 1);

    
    delete [] graph.node_list;

    return 0;
}

node::node(int node, int count, const int* arc)
{
    m_arc_count = count;
    m_node = node;
    m_arc = new int[m_arc_count];
    m_visit = false;

    if (count)
    {
        for (int i = 0; i < count; i++)
        {
            m_arc[i] = arc[i];
        }
    }
}

void dfs(arr_node graph, int i_startNode)
{
    using std::cout;
    node* startNode = getNodePointer(graph, i_startNode);
    std::stack<node*> st;
    st.push(startNode);

    int loop = 0;;

    //getNodePointer(graph, st.top()->getArc(i))->isVisit() 가장 위의 
    while (true)
    {
        loop++;
        
        //st.top()->user_print();
        st.top()->vist();
        int nextNode;
        int isPush = 0;
        for (int i = 0; i < st.top()->getArcCount(); i++)
        {
            //cout << st.top()->getArc(i);
            node* checkNode = getNodePointer(graph, st.top()->getArc(i));
            if (false == checkNode->isVisit())
            {
                isPush++;
                st.push(checkNode);
                break;
            };
        };
        if (isPush == 0)
        {
            st.pop();
        }
        //cout << "Push" << isPush << "\n";
        if (st.empty()) break;
    }
    
}