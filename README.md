# backend_framework

After that you received the request in your C socket server, 

count = recv( descriptor , buffer , size , 0);

just call the function backend_framework(); will return the size of the response and fill the buffer with the response.

size = backend_framework( buffer , count );


In backend_framework.c -> get("route" , controller) , post("/",ctrl) you can define wich routes your server has, and which controller to call, like the modern frameworks.

In controllers you can send pictures(binary), html files(text), add response headers, and get the request body, like the modern frameworks.
(request and response are global and have the buffer than tecnically you can always all)
But like this is like modern frameworks. in 30kb
