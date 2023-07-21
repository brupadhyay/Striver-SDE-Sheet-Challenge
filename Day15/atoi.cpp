/**
 * TC - O(n)
 * SC - O(1)
*/
int atoi(string str) {
    int integer = 0;
    for(char c: str){
        if(c >= '0' && c <= '9'){
            integer = integer*10 + c - '0';
        }
    }
    if(str[0] == '-') return -integer;
    return integer;
}