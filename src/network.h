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

/* Enumeration of HTTP methods,
 * inluding GET, PUT, DELETE, POST and PATCH. */
typedef enum {
  GET, PUT, POST, PATCH, DELETE
} Method;

/* This structrue wraped RESTful HTTP request */
typedef struct {
  Method  method;       /* HTTP method: POST, GET, etc. */
  char*   url;          /* Target URL */
} RestRequest;

#endif
