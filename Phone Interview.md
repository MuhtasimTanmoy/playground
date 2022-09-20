# Phone Interview
- Logical maintainable extensible code output
- My experinece with backend was give api interface, call orm, review the query the orm generated, make improvements in it, cache it if needed, with proper serialization deserialization send it


# LP

Customer Obsession
    - Fixing crash reports
Ownership
    - XMPP module fully maintained by me. So, SwiftUI long term. 
Invent and Simplify
    - SwiftUI
Are Right, A Lot
    - SwiftUI
Learn and Be Curious
    - webRTC, XMPP, signal
Hire and Develop The Best
Insist on the Highest Standards
    - Signal
Think Big
    - Signal
Bias for Action
Frugality
    - Our whole development process is example of frugality
Earn Trust
    - my seniors trusted me to do that
Dive Deep
    - webRTC, XMPP, signal
Have Backbone; Disagree and Commit
    - SwiftUI
Deliver Results
    - webRTC, XMPP, signal


- Critical feedback
    - I once got feed negative feedback from my direct reporting manager, that though I was fully working on optimizing performance, pixel perfect ui, but I overlooked the text content. Actually we have figma design and we copy text from there, so I got text from it, used it and done but the problem is that I ignored full stop, or other things and he said use my best judgement there as well and to have attention to detail for the overall project and everything as the whole module app is my responsibility.

- Disagreement, Think in long term, Have backbone disagree or commit
    - The team I am working on has 5 memebers in total including me and 3 of them is 3 to 4 years experineced in this field. It strictly followed mvvm and autolayout. But as swiftUI came which is available from iOS 13 only. I was the first to adopt and start working on it. Another reason was that, I am used to functional reactive programming and I used swiftui in a feature that was included in out sprint with deadline. It significantly lessen the code surface also the testing improved lot as it is real time reflected alongside. But there was minor disagreement tha tI should use it later.
    There will be other developers and they need to maintain the code. 

- What you are proud of doing?
    - There are so many xmpp specifications
        - Like group chat, profile management, online users
    - Encryption
        - Tell about client, server encryption
-  Prekey bundle
    - `IPKb`
        - Identity public key bundle
        - Generated once and saved locally
    - `SPKb` 
        - Signed public key bundle 
        - To verify control over the public key
        - Generated once and saved locally
    - `OPKb` 
        - Optional private key bundle 
        - Used for session establishment when offline
        - Uploaded to keybase on server
        - Once fetched by the counterpart it is deleted from keybase / server
        - When received from counterpart with this key it is deleted from local list as well to avoid replay attack

- For each message it gets changed
    - Perfect forward secrecy

- Dive Deep
    - LLVM, BitCode, WebRTC, XMPP
    - Use macro to use same file source to compile for different binary
    - ```
    func update(val: Int) {
        newValue = val
        persist()

        #if notification_extension
        publishForViewUpdate()
        #
    }
    ```

- Unit testing speed up the development process by a lot

- Frugality
    - Device limit did save lots of time for developers and users

## Question
