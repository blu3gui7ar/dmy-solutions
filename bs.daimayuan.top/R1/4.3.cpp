#include <bits/stdc++.h>
using namespace std;

 #define LOG(msg) \
    // cout << "[" << __FILE__ << ":" << __LINE__ << "] " << msg << endl

struct Group
{
    int size;
    int loop;
    int body[200001];

    Group()
    {
        size = 0;
        loop = -1;
        memset(body, 0, sizeof(body));
    }
};

struct Node
{
    Group *group;
    int pos;
    Node()
    {
        group = NULL;
        pos = 0;
    }
};
void dump(Node (&nodes)[200001], int n)
{
    for (int i = 1; i <= n; i++)
    {
        Node &node = nodes[i];
        cout << "node " << i << " pos " << node.pos;
        if (node.group != NULL)
        {
            cout << " => group(" << node.group->size << ")|" << node.group->loop << ":";
            for (int j = 0; j < node.group->size; j++)
            {
                cout << " " << node.group->body[j];
            }
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;
    int a[200001] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    Node nodes[200001];

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        long s, c;
        cin >> s >> c;

        int current = s;
        Group *current_group = nodes[s].group;
        int last_pos = -1;
        for (int j = 0; j < c; j++)
        {
            LOG(i << ":" << j + 1 << "/" << c);
            LOG("step: " << current << " => " << a[current]);
            Node &node = nodes[current];
            Group *group = node.group;
            if (group == NULL)
            {
                if (j == 0)
                {
                    current_group = new Group();
                    LOG("new group");
                }
                LOG("update group");
                group = current_group;
                node.group = current_group;
                node.pos = group->size;
                group->body[group->size++] = current;
                last_pos = node.pos;
                current = a[current];
            }
            else
            {
                if (group == current_group)
                {
                    LOG("Same group detected. last_pos: " << last_pos << " node.pos: " << node.pos);
                    // cycle detected
                    if (last_pos >= node.pos)
                    {
                        if (group->loop == -1 || group->loop > node.pos)
                        {
                            LOG("cycle detected");
                            LOG("loop at pos: " << node.pos);
                            group->loop = node.pos;
                        }
                    }
                }
                int to_go = c - j;
                LOG("Steps to go: " << to_go);
                if (group->loop != -1)
                {
                    // group with loop, can calculate the result
                    int to_end = group->size - node.pos;
                    LOG("Found group with loop(" << group->loop << "):" << node.pos << " tail: " << to_end);
                    if (to_go < to_end)
                    {
                        LOG("Straight: " << to_go);
                        current = group->body[node.pos + to_go];
                    }
                    else
                    {
                        to_go -= to_end;
                        int loop = group->size - group->loop;
                        to_go %= loop;
                        LOG("Loop Tail: " << to_go);
                        current = group->body[group->loop + to_go];
                    }
                    break;
                }
                else
                {
                    LOG("Found group without loop");
                    if (to_go < group->size - node.pos)
                    {
                        // end at this group
                        LOG("Straight: " << to_go);
                        current = group->body[node.pos + to_go];
                        break;
                    }
                    else
                    {
                        int jump = group->size - node.pos - 1;
                        LOG("Try jump at: " << node.pos << " in group(" << group->size << ")");
                        if (jump > 0)
                        {
                            // jump to the end of this group
                            LOG("Jump: " << jump);
                            current = group->body[group->size - 1];
                            j += jump;
                            last_pos = group->size - 1;
                        }
                        else
                        {
                            LOG("One Step");
                            // continue
                            last_pos = node.pos;
                            current = a[current];
                        }
                    }
                }
                // current_group = group;
            }
        }
        cout << current << endl;
        // dump(nodes, n);
    }

    return 0;
}