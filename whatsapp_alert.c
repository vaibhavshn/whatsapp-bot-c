#include "whatsapp_alert.h"

int whatsappSendMessage(char *number, char *message)
{

    curl = curl_easy_init();

    if (curl)
    {

        // Show the details being sent
        printf("Sending:");
        printf("\n\tNumber  : %s", number);
        printf("\n\tMessage : %s", message);

        // Initialize string linked list for adding headers
        struct curl_slist *chunk = NULL;

        // Appending header strings to chunk.
        chunk = curl_slist_append(chunk, "Cache-Control: no-cache");
        chunk = curl_slist_append(chunk, "Content-Type: application/x-www-form-urlencoded");
        chunk = curl_slist_append(chunk, API_KEY);

        // URL Escaping the message
        message = curl_easy_escape(curl, message, strlen(message));

        // The POST parameter string initialized
        char post_field[1 + strlen(PARAMS) + strlen(message) + strlen(number) + strlen("&destination=&message=")];

        // Copy all parameters into post_field
        strcpy(post_field, PARAMS);
        strcat(post_field, "&destination=");
        strcat(post_field, number);
        strcat(post_field, "&message=");
        strcat(post_field, message);

        // Set headers
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        // Set POST parameters
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_field);

        puts("\nReceived response:");

        // Perform the request, res will get the return code 
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_slist_free_all(chunk);
            return 0;
        }

        puts("");

        // Cleaning up
        curl_easy_cleanup(curl);
        curl_slist_free_all(chunk);

        return 1;
    }
    else
    {
        printf("Error! Please initialize the library with the function 'whatsappInit()'.\n");
        return 0;
    }
}