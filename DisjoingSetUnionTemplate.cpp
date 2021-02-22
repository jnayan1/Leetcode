int find(int u)
{
    if(u == representative[u])
        return u;
    
    else
        return representative[u] = find(representative[u]);
}

void combine (int u, int v)
{
    u = find(u);
    v = find(v);
    
    if(u == v)
        return;
    
    else
    {
        if(rank[u] > rank[v])
        {
            representative[v] = u;
            rank[u] += rank[v];
        }
        
        else
        {
            representative[u] = v;
            rank[v] += rank[u];
        }
    
    }
}
