/*
* Are we allowed to declare free fuunction as const???
*/

void free_function() const{ // compiler error: free_function() cannot be const
    return;
}

int main(){
    free_function();

    return 0;
}