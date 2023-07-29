#include <event2/event.h>
#include <event2/http.h>
#include <event2/http_struct.h>
#include <event2/keyvalq_struct.h>
#include <event2/buffer.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Callback function for handling HTTP GET responses
void http_get_cb(struct evhttp_request *req, void *arg)
{
    if (req == NULL) {
        printf("HTTP GET request failed\n");
        return;
    }

    // Get the response body buffer
    struct evbuffer *buf = evhttp_request_get_input_buffer(req);
    size_t len = evbuffer_get_length(buf);

    // Print the response body
    char *response = malloc(len + 1);
    memset(response, 0, len + 1);
    evbuffer_remove(buf, response, len);
    printf("HTTP GET response body: %s\n", response);
    free(response);

    // Clean up the request and associated resources
    evhttp_request_free(req);
}

// Callback function for handling HTTP POST responses
void http_post_cb(struct evhttp_request *req, void *arg)
{
    if (req == NULL) {
        printf("HTTP POST request failed\n");
        return;
    }

    // Get the response body buffer
    struct evbuffer *buf = evhttp_request_get_input_buffer(req);
    size_t len = evbuffer_get_length(buf);

    // Print the response body
    char *response = malloc(len + 1);
    memset(response, 0, len + 1);
    evbuffer_remove(buf, response, len);
    printf("HTTP POST response body: %s\n", response);
    free(response);

    // Clean up the request and associated resources
    evhttp_request_free(req);
}

int main()
{
    // Initialize the event base
    struct event_base *base = event_base_new();

    // Initialize the HTTP client
    struct evhttp_connection *conn = evhttp_connection_base_new(base, NULL, "www.example.com", 80);

    // Create an HTTP GET request
    struct evhttp_request *get_req = evhttp_request_new(http_get_cb, NULL);
    evhttp_add_header(evhttp_request_get_output_headers(get_req), "Host", "www.example.com");
    evhttp_add_header(evhttp_request_get_output_headers(get_req), "Connection", "close");
    evhttp_make_request(conn, get_req, EVHTTP_REQ_GET, "/");

    // Create an HTTP POST request
    struct evhttp_request *post_req = evhttp_request_new(http_post_cb, NULL);
    evhttp_add_header(evhttp_request_get_output_headers(post_req), "Host", "www.example.com");
    evhttp_add_header(evhttp_request_get_output_headers(post_req), "Connection", "close");
    struct evbuffer *post_data = evbuffer_new();
    evbuffer_add_printf(post_data, "param1=value1&param2=value2");
    evhttp_add_header(evhttp_request_get_output_headers(post_req), "Content-Length", "%d", evbuffer_get_length(post_data));
    evhttp_make_request(conn, post_req, EVHTTP_REQ_POST, "/", post_data);

    // Run the event loop
    event_base_dispatch(base);

    // Clean up the HTTP client and associated resources
    evhttp_connection_free(conn);

    // Clean up the event base
    event_base_free(base);

    // Clean up the POST data buffer
    evbuffer_free(post_data);

    return 0;
}

