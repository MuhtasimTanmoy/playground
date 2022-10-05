- Messenger IOS

- Chat, Group Chat module, and Connection managenment
    - There are so many micro interactions
    - In case I am sharing any media and the network is down, manage delivered, seen acknowledgement of all messages
    - The message needed to sync from other devices
    - Also after the network is connected all messages that were failed or pending needed to be send again
    - There are around 45-50 types of message and each would trigger different task, some would trigger 4-5 independent task. 
    - Like location, seen, displayed, media, theme, reply message. Like for group message we sort of needed to track each message is seen by which member at which time stamp.
    - No shared variable, after every 15 days I refactored portion of it to make amendments for my lack of discipline
    - `tail -23000 ejabberd.log | head -50`
    - There was lots of custom XML parsing, unit testing sort of very much accelerated this process, and we sort of have github action validating this process
    - Events for analytics which feature is mostly being used by our users
    - Minimum code change to achieve the result
    - Each group creation, member addition required 5-6 round trip to server

- Call
    - I worked on our webrtc connection meta exchange handshake
    - Stun server 
        - It is just a reflection server, you make a call, you get meta the ip it was requested, 
        cause our device can be behind a NAT
    - Turn server
    - SDP providing the client capabilities, like for audio opus codec, video vp8 codec
    - ICE candidate provides the information about the ipaddress and port from where the data is going to be exchanged.
    - The data channel has multiplexing for other types of data

- Bitcode Enable
    - I'm not sure at what level you are looking for an answer at, so let's take a little trip. Some of this you may already know.
    -  When you build your project, Xcode invokes clang for Objective-C targets and swift/swiftc for Swift targets. Both of these compilers compile the app to an intermediate representation (IR), one of these IRs is bitcode. From this IR, a program called LLVM takes over and creates the binaries needed for x86 32 and 64 bit modes (for the simulator) and arm6/arm7/arm7s/arm64 (for the device). Normally, all of these different binaries are lumped together in a single file called a fat binary.
    - The ENABLE_BITCODE option cuts out this final step. It creates a version of the app with an IR bitcode binary. This has a number of nice features, but one giant drawback: it can't run anywhere. In order to get an app with a bitcode binary to run, the bitcode needs to be recompiled (maybe assembled or transcoded… I'm not sure of the correct verb) into an x86 or ARM binary.
    - When a bitcode app is submitted to the App Store, Apple will do this final step and create the finished binaries.

- Other
    - Events running for sending 100 messages

- Correction / Deletion
- received acknowledgement
- displayed acknowledgement
- composing state
- paused state 
- location stop
- location request
- Encrypted message
- Error message in case the server buffer is full, which is configurable
- invalid
- text
- photo
- file
- call
- sticker
- location
- audio
- linkPreview
- feed
- story
- customPacket
- imageGroup
- GIF
- packetCollected
- video
- chatInfoChange
- Remove
- missCall
- reply
- attributedText // mention someone
- contact = 25
- themeChange = 118
- roomInfoChange = 120
- onFnFAddComplete = 121
- addFnF = 122
- congratsOnFnF = 123
- groupImageChange = 124
- nickNameChange = 125
- poll = 126
- pollVoteCast = 127
- userInfoChange = 200
- introductory
- spinLoader
- game
- callerTune

- Notification extension, another app which is short lived, we needed to show callkit, to show native call interface

case remove
case call(String)
case misscall(String)
case reply(Reply)
case linkPreview(LinkPreviewContent)
case feed(FeedMessage)
case story(FeedMessage)
case packet(Packet)
case packetCollected(Packet.Collected)
case sticker(StickerContent)
case attributedText(MessageAttributedString)
case gif(GIFModel.GIF)
case file(FileContent)
case roomMemberChangeInfo(RoomMemberChangeInfo)
case roomImageChangeInfo(RoomImageChangeInfo)
case nickNameChangeInfo(NickNameChangeInfo)
case theme(ThemeMeta)
case poll(Poll)
case pollUpdate(PollUpdate)
case onFnFAddComplete
case addFnF // In memory only
case congratsOnFnF(Int)
case invalid
case introductory
case spinLoader
    