
/* INFO ABOUT REQUEST

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



// GET CONTROLLERS

// /favicon.ico
void ctrl_favicon(){
        response_send_pic("image.jpeg");

}

// /
void ctrl_home(){

        add_response_header("Server: E-pache 1.0");
        response_send_file("views/html.html");

}





// POST CONTROLLERS
void ctrl2(){
        response_send_pic("image.jpeg");
}