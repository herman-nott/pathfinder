#include "../inc/libmx.h"

int mx_sqrt(int x)
{
    if (x == 1)
        return 1;
    
    for (int root = 1; root <= x / 2; root++)
    {
        if (root * root == x)
            return root;
    }
    
    return 0;
}
