#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<time.h> 
using namespace std;
double maxdist = 999999999;

class edge
{
public:

    double alpha;
    double tz;
    int fcar;
    double w;
    double wi()
    {
        return tz * (1 + alpha * fcar);
    }
    edge()
    {
        fcar = 0;alpha = 0;tz = 0;w = maxdist;
    }

};
class node
{
public:
    int vi;
    double di;
    bool friend operator < (node n1, node n2)   //设置优先级
    {
        return n1.di > n2.di;
    }

};
class request
{
public:
    int s;
    int t;
};
class answer
{
public:
    vector<int> t;
};


void Dijkstra(int n, int v, int u, int* pre, int** d, edge* e, vector<vector<int>> adjust)
{

    double dist[401];


    vector<bool> s(n + 1);
    priority_queue<node> que;

    for (int i = 0; i < n;i++)
    {
        dist[i] = e[d[v][i]].w;
        if (dist[i] < maxdist)
            pre[i] = v;
        else
            pre[i] = -1;
    }
    dist[v] = 0;

    node now;
    now.vi = v;
    now.di = dist[v];
    que.push(now);
    int best = v;
    while (!que.empty())//总的迭代次数
    {
        node topnode = que.top();
        que.pop();


        if (!s[topnode.vi])
        {
            best = topnode.vi;
            s[best] = true;



            if (best == u)
                return;

            for (int j = 0; j < adjust[best].size();j++)//更新dist和pre
            {
                int t = adjust[best][j];
                if (!s[t])
                {
                    double newdist = dist[best] + e[d[best][t]].w;
                    if (newdist <= dist[t])
                    {
                        dist[t] = newdist;
                        pre[t] = best;
                        node temp;
                        temp.vi = t;
                        temp.di = dist[t];
                        que.push(temp);
                    }
                }
            }

        }
    }
}





int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int m, E, n;
        cin >> m >> E >> n;
        vector<answer> ans(n);
        int** g = new int* [m + 1];
        for (int i = 0; i < m + 1; i++)
            g[i] = new int[m + 1];

        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < m;j++)
                g[i][j] = 10001;
        }
        edge e[10002];
        e[10001].w = maxdist;
        vector<vector<int>> adjust(405);
        vector<request> req;
        for (int i = 0;i < n;i++)
        {
            int s, t;
            cin >> s >> t;
            request temp;
            temp.s = s;
            temp.t = t;
            req.push_back(temp);
        }

        for (int i = 0;i < E;i++)
        {
            int u, v;
            double q, a, b;
            cin >> u >> v >> q >> a >> b;
            g[u][v] = 2 * i;
            g[v][u] = 2 * i + 1;
            e[2 * i].tz = q;
            e[2 * i + 1].tz = q;
            e[2 * i].alpha = a;
            e[2 * i + 1].alpha = b;
            e[2 * i].w = e[2 * i].wi();
            e[2 * i + 1].w = e[2 * i + 1].wi();
            adjust[u].push_back(v);
            adjust[v].push_back(u);

        }
        srand(time(NULL));
        vector<bool> flag(n);
        for (int i = 0;i < n;i++)
            flag[i] = 0;
        int count = 0;
        const int N = 50;
        int re[N];
        for (int i = rand() % n;count <= n + N;i = rand() % n)
        {
            if (flag[i] == 1)
                continue;
            if (count > N)
                flag[i] = 1;
            count++;
            int pre[401];
            Dijkstra(m, req[i].s, req[i].t, pre, g, e, adjust);

            int init = req[i].s;
            int fina = req[i].t;
            int temp = fina;
            int r[401];

            int c = 0;
            while (temp != init && c < 401)
            {
                r[c] = temp;
                c++;

                temp = pre[fina];
                fina = temp;
            }
            answer tem;
            tem.t.push_back(init);
            tem.t.push_back(g[init][r[c - 1]]);
            //cout << c * 2 + 1 << endl;
            //cout << init << " " << g[init][r[c - 1]] << " ";
            e[g[init][r[c - 1]]].fcar++;
            e[g[init][r[c - 1]]].w = e[g[init][r[c - 1]]].wi();
            for (int i = c; i > 1;i--)
            {
                int a = r[i - 1];
                int b = r[i - 2];
                //cout << a << " " << g[a][b]<< " ";
                tem.t.push_back(a);
                tem.t.push_back(g[a][b]);
                e[g[a][b]].fcar++;
                e[g[a][b]].w = e[g[a][b]].wi();
            }
            //cout << r[0] << endl;
            tem.t.push_back(r[0]);
            ans[i] = tem;
        }

        for (int i = 0;i < n;i++)
        {
            int c = ans[i].t.size();
            cout << c << endl;
            for (int j = 0;j < c - 1;j++)
                cout << ans[i].t[j] << " ";
            cout << ans[i].t[c - 1] << endl;

        }

    }
}