
/* // // // // // // // // // // // // // // // // // //    INFO ABOUT REQUEST

struct HTTP_request{
    char* method;
    char* URI;
    char* HTTP_version;
    unsigned int headers_count;
    char** headers;
    unsigned int attributes_count;
    char* body;
}http_request;

*/

// // // // // // // // // // // // // // // // // // // // GET CONTROLLERS


//#########################################################################
//          P R E L U D E     O F     V I E W    E N G I N E              #
//#########################################################################
    // this function is to keep as it is.. dont modulate it
    int find_in_str (char * text, char* from , char* to , unsigned int* indexes){
        unsigned int i = 0;
        char frs_c = from[0];
        char lst_c = to[ ( str_len(to)-1 ) ];
        char c = text[0];
        unsigned int delicious_lasagna(char* text, unsigned int i , char* begin  , char* end) {
            u8 bg_sz = str_len(begin);
            u8 nd_sz = str_len(end);
            unsigned int index_begin = 0;
            unsigned int index_end = 0;
            unsigned int j = 0;
            if(str_cmp( bg_sz , begin , &text[i] ) ){
                index_begin = i;
                j = bg_sz;
                while ( text[ i + j ] != '\0'){
                    if( text [i + j] == end[0]){
                        if (str_cmp(nd_sz , end , &text[i+j])){
                            index_end = i + j + nd_sz - 1;
                            return index_end;
                        }
                    }
                    j++;
                }
            } 
            return 0;
        }
        unsigned int counter = 0;
        unsigned int index_end = 0;
        while (c != '\0'){
            if(c == frs_c){
                // check if
                index_end = delicious_lasagna( text , i , "<-" , "->");
                if(index_end != 0){
                    indexes[counter] = i;
                    indexes[counter+1] = index_end;
                    i+= index_end;
                    index_end = 0;
                    counter += 2;
                    printf("i = %u \n" , i);
                }else{
                    break;
                }     
            }
            i++;
            c = text[i];
        }
        return counter;
    }
//#########################################################################
//          P R E L U D E     O F     V I E W    E N G I N E     (end)    #
//#########################################################################


//#########################################################################
//          P R E L U D E     O F     E - P A C R E E P T                 #
//#########################################################################

void prelude_epacreept(){
    // those will work on parallel
    // is the list of the variables in the environment of E-pacreept.ec

    const unsigned int size = 126;
    char *vars[size];
    char *values[size];
    
    char arrayend[] = "arrayend";
    vars[0] = arrayend;
    values[0] = arrayend;


    void add_var(char* varname , char* value ){
        unsigned int i = 0;
        while( !str_cmp( str_len(vars[i]) , vars[i] , arrayend ) ){
            printf("\npresent: %s = %s" ,vars[i] ,values[i] );
            i++;
        }
        vars[i] = varname; 
        values[i] = value;
        vars[i+1] = arrayend;
        values[i+1] = arrayend;
        printf("\nadded var: %s , value: %s\n\n" , vars[i] , values[i] );
    }
    
    add_var("user"  , "User_Name@http.com");

    add_var("password"  , "************************");

    add_var("tree_structure"  , "abc{abc2{abc2.0;abc2.1;abc2.3}abc3{abc3.O;abc3.1}}");

    add_var("brunch_users"  , "name,password,profileid");

}

//#########################################################################
//          P R E L U D E     O F     E - P A C R E E P T       (end)     #
//#########################################################################








// '/favicon.ico'
void ctrl_favicon(){
    response_send_pic("E-pachy_512x512.png");
}

    // '/'
void ctrl_home(){

    // unsigned int indexes[512];
    // char* text = "hello <-abc-> hello2 ,<- ansdn <-sdlkjsd slkjslkja ,lks <-a dklslkjd->lkjsd b->";

    // unsigned int counter = find_in_str( text , "<-" , "->" , indexes );

    // for (u8 i = 0 ; i < counter; i++ ) printf("[%u]" , indexes[i] );

    prelude_epacreept();


    add_response_header("Server: E-pache 1.0");
    response_send_file("views/html.html");
}


// // // // // // // // // // // // // // // // // // // // // POST CONTROLLERS
// '/'
void ctrl2(){
        response_send_pic("E-pachy_512x512.png");
}