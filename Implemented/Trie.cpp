
// Initialization

struct node{

bool ending;
node *next[26];
node()
{
    ending=false;
    for(int i=0;i<26;i++)
        next[i]=NULL;
}
}*root;

//Insertion

void Insert(char *str, int len)
{
    node* curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->ending=1;
}


//Searching

void Search(char *str, int len)
{
    node* curr= root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return ending;
}

//Deletion of the entire Trie

void del(node* curr)
{
    for(int i=0;i<26;i++)
        if(curr->next[i])
            del(cur->next[i]);
    delete(curr);
}
