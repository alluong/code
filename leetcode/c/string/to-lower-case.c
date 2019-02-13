char* toLowerCase(char* str) {
    int ii;
    
    for (ii = 0; ii < strlen(str); ii++) {
        if (str[ii] >= 'A' && str[ii] <= 'Z') {
            str[ii] = str[ii] + 'a' - 'A';
        }
    }
    return str;
}
