# Writing the Library



Now, we've created the bot and have access to the API endpoint and the key to communicate with it.
We'll be using the libcurl library, so make sure you have installed it.
If you don't have it, install it with:

```bash
apt-get install libcurl4-openssl-dev
```



Here are the parameters we'll be using in our code. Note that 91 is the country code for India, you may change it to your country code. The below JSON is just to demonstrate the variables in use.

```json
{
    "channel": "whatsapp",
    "source": "91[<the-gupshup-assigned-number> or <your-phone-number-after-you-go-live>]",
    "destination": "<country-code without '+' prefix><your-number>",
    "src.name": "OpenVentiBeta",
    "message": "Your Message here!"
}
```

First, let us define them in the header file `whatsapp_alert.h`.

```c
// File: whatsapp_alert.h
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

#define URL "https://api.gupshup.io/sm/api/v1/msg"
#define API_KEY "apikey: fc4caa81ca06489fc8734698a72028ee"
#define PARAMS "channel=whatsapp&source=917834811114&src.name=OpenVentiBeta"
```

You may need to change the source phone number in `PARAMS`.

The functions defined in libcurl which we'll be using in our library:

| Function                 | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| curl_easy_init()         | Initializes a curl session                                   |
| curl_slist_append()      | Adds HTTP Headers                                            |
| curl_easy_escape(string) | URL Escapes the string passed to it, so that it can be sent over HTTP methods |
| curl_easy_setopt()       | It is used to set the required option to a specific value.   |
| curl_easy_perform()      | Perform the request and print the response.                  |
| curl_easy_cleanup()      | Cleans up the session.                                       |
| curl_slist_free_all()    | Frees up an slist (string linked list)                       |



We'll also be using the curl session handler variable and the result code variable which returns the result of a request. Here's the full `whatsapp_alert.h` code:

```c
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

#define URL "https://api.gupshup.io/sm/api/v1/msg"
#define API_KEY "apikey: fc4caa81ca06489fc8734698a72028ee"
#define PARAMS "channel=whatsapp&source=917834811114&src.name=OpenVentiBeta"


CURL *curl;
CURLcode res;

int whatsappSendMessage(char *number, char *message);
```

Check out the `whatsapp_alert.c` and `whatsapp_alert_example.c` file for more details.

The function `whatsappSendMessage()` returns **1** if the message was sent, and **0** if it wasn't.



## References

- lcurl API
  https://curl.haxx.se/libcurl/c/