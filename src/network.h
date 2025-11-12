/*
 *  ______ _    _ _______
 * / _____| |  | |__   __|
 * | |  __| |__| |  | |
 * | | |_ |  __  |  | |
 * | |__| | |  | |  | |
 * \______|_|  |_|  |_|
 *
 * network.h
 *
 * Copyright (C) 2025   Steve Pan
 *
 * This file is part of GitHubTui (GHT) project.
 *
 * Built on top of cURL.
 *
 * Provides functionality for handling RESTful API communication.
 */

#ifndef GHT_NETWORK_H
#define GHT_NETWORK_H

#include <stddef.h>

/* Enumeration of HTTP methods,
 * inluding GET, PUT, DELETE, POST and PATCH. */
typedef enum { GET, PUT, POST, PATCH, DELETE } Method;

/* Represents a single HTTP header key-value pair. */
typedef struct {
    const char *key;   /* Header field name */
    const char *value; /* Header field value */
} HttpHeader;

/* Represents an HTTP response.*/
typedef struct {
    long   statusCode;
    char  *body;
    size_t body_size;
} RestResponse;

/* This structrue wraped RESTful HTTP request */
typedef struct {
    Method       method;      /* HTTP method: POST, GET, etc. */
    char        *url;         /* Target URL */
    char        *proxy;       /* Optional proxy (NULL if unused) */
    HttpHeader  *headers;     /* Array of HTTP headers */
    int          headerCount; /* Number of headers in the array */
    char        *body;        /* Optional request body (for POST/PUT/PATCH) */
    size_t       bodySize;    /* Size of the request body in bytes */
    long         timeout;     /* Timeout in seconds */
    RestResponse response;    /* Response data */
} RestRequest;

void restSend(RestRequest *req);
void restFree(RestRequest *req);

#endif
