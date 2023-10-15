unsigned int file_load(char *buffer , char* filename){
    FILE * fp = fopen(filename,"r");    
    if(fp == NULL) printf("\nERROR OPENING FILE %s\n", filename);
    char c = fgetc(fp);
    unsigned int count = 0;
    while ( c != EOF){
        buffer[count++] = c;
        c = fgetc(fp);
    }
    buffer[count] = '\0';
    fclose(fp);
    return count;
}


unsigned int get_pic(int8_t *buffer , char*filename){

    FILE *pic ;
    int i;
    pic = fopen(filename, "rb"); 

    if( pic == NULL ) { printf("Error opening File\n");} 

    fseek(pic, 0, SEEK_END);
    int length = ftell(pic);
    fseek(pic, 0, SEEK_SET);

    for(i = 0; i < length; i++){
        buffer[i] = fgetc(pic);
    }

    fclose(pic); 
    return length;

}