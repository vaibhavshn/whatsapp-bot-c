# Gupshup.io WhatsApp Bot

We'll be creating a WhatsApp bot which sends alert messages from a program and library we will write for accessing and using Gupshup.io's APIs since they are affiliated to WhatsApp for their Business API.

Let's start.

1. First, create an account with Gupshup.io for using their WhatsApp bot API and to get that API key, by going to the link and signing up.

   >  **NOTE** 
   > If you want to just test it out, you can do so, but if you want to go live and use the bot in production, then use the suitable email account, because it cannot be changed later on and you cannot move apps and app data to another account.
   >
   > You're given $1 credits to test your app in their sandbox mode. Do not overuse it by sending many number of messages, since it's for development purpose.

   


   ```
   https://www.gupshup.io/developer/whatsapp-api
   ```

2. Now, click "Create your App" in the Dashboard.
   Provide the name you'll be giving to the App, this will be reflected in the WhatsApp account as well.
   I am naming the bot I create: `OpenVentiBeta`

3. Select the type of bot you want it to be, here, for example, we will choose "Template Notifications" because we just want to send alert messages, not interact with users.

4. Now, your bot will have been created, it's really a simple and guided process, you can just follow along their guide. But nevertheless, in case you get stuck.
   Now, to test out your app, you need to **opt-in** to receive alerts as shown in the page.
   Opt in via any method you wish.

5. In Step 3 of the guide, you can now send message to the numbers who have **opted in**.
   Please note, you cannot send messages to a number which hasn't opted in to receive messages from your bot.
   Try sending a message to your number. :)

6. Also note the CURL command displayed below the message send dialog box. Mine was:

   CURL command to send a message:

   ```bash
   curl -X POST https://api.gupshup.io/sm/api/v1/msg \
   -H 'Cache-Control: no-cache' \
   -H 'Content-Type: application/x-www-form-urlencoded' \
   -H 'apikey: <an-api-key-comes-here>' \
   -H 'cache-control: no-cache' \
   -d 'channel=whatsapp&source=917834811114&destination=9194xxxxxxxx&message=Hello,%20welcome%20to%20OpenVenti!&src.name=OpenVentiBeta'
   ```

   We'll be using the following data in making our library:

   - The URL (and the HTTP method used, which is POST)

   - The 4 headers (actually, there's one header duplicated, so technically 3)

   - The parameter list (shown in JSON for readability)

     ```json
     {
         "channel": "whatsapp",
         "source": "91[<the-gupshup-assigned-number> or <your-phone-number-after-you-go-live>]",
         "destination": "91<your-number>",
         "src.name": "OpenVentiBeta",
         "message": "Your Message here!"
     }
     ```

   We'll use all the parameters as is, except the phone number and the message, because they are variable and we want to send any message to any number which is opted in.

Now, please follow along the remainder of this guide, which is writing the library and the example with the help of the `libcurl` library in C.

> **NOTE**
> If you're planning to take the app live, you will need to use your own phone number and have a verified FB Business Page as stated in the Gupshup.io dashboard. Visit the dashboard for more details.


[Next >>](Writing-the-Library.md )

[Next]: Writing-the-Library.md