///Initialization

void makeset(n)
{
    parent[n]=n;
    size[n]=1;                 /// Initializing the size of each element to 1.
    /// While connecting two nodes, if we set the parent of the node
    /// with bigger size as the parent of both nodes,
    /// it will reduce the complexity of union() and find() as they will
    /// need to traverse a lot less
}

for( iterate through the nodes )
    makeset(i in range)

///Finding the parent of a node

    find(r)
{
    if(par[r]==r)
        return r;
    par[r]= find(par[r]);      /// Path compression: Everytime the find() function is called,
    /// we change the parent of the parameter to its grandparent until
    /// we reach the root
    ///At the end, all the connected nodes have the same parent
    return par[r];
}


///Connecting two nodes


union(a, b)
{
    u = find(a);
    v = find(b);
    if( u==v )
        return;
    if( size[u] < size[v] )
    {
        par[u] = v;
        size[v]+= size[u];
    }
    else
    {
        par[v] = u;
        size[u]+= size[v];
    }

}


