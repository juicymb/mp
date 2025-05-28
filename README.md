<h1 align="center">
  <br>
  <a href="http://https://github.com/anggorodhanumurti/themaphack/"><img src="https://raw.githubusercontent.com/anggorodhanumurti/themaphack/refs/heads/main/images/tmh-logo.png" alt="tmh" width="200"></a>
  Themaphack.
</h1>
<h3 align="center"> Mod menu like no others</h3>
<p align="center">
  <a href="https://whatismyandroidversion.com/"><img src="https://img.shields.io/badge/Android-10--14+-brightgreen?logo=android" alt="Android - 10-14+">
  </a>
  <a href="https://play.google.com/store/apps/details?id=com.mobile.legends"><img src="https://img.shields.io/badge/Game-Mobile_Legends-important?logo=youtubegaming" alt="Game - Mobile Legends">
  </a>
  <a href="https://t0pgamemurah.xyz/freeKey"><img src="https://img.shields.io/badge/generate-key-blue?logo=keeweb&logoColor=fff" alt="generate - key">
  </a>
  <a href="https://github.com/anggorodhanumurti/themaphack/releases/"><img src="https://img.shields.io/github/tag/anggorodhanumurti/themaphack?include_prereleases=&sort=semver&color=blue" alt="GitHub tag"></a>
<a href="#license"><img src="https://img.shields.io/badge/License-GPL_3.0-blue" alt="License"></a>
  <a href="https://www.paypal.me/">
    <img src="https://img.shields.io/badge/$-donate-ff69b4.svg?maxAge=2592000&amp;style=flat">
  </a>
</p>

![screenshot](https://raw.githubusercontent.com/anggorodhanumurti/themaphack/refs/heads/main/images/themaphack-demo.gif)

<p align="center">
  <a href="#key-advantage">Key Advantage</a> •
  <a href="#main-features">Main Features</a> •
  <a href="#build">Build</a> •
  <a href="#download">Download</a> •
  <a href="#usage">Usage</a> •
  <a href="#faq">FAQ</a>
</p>

## Key Advantage

The fact that there is no 100% cheats that safe from being banned.

Remember when you paid for premium mod just for 30 days they claim it safe but end up getting banned for 30 years (even when the usage duration not yet over).

You lost your acount without refund that suck! we dont want to overclaim but here the best thing we can give:

* Free forever
  - You can generate free key (unlimited) in our [website](https://t0pgamemurah.xyz/freeKey).
  
* Open source, Transparency & Modular
  - feel free to use this source code as a template for your mod menu project
  - you dont need to trust me just inspect the code yourself and build it, there is no malicious code inside
  - you can extend the feature of this mod to suits your needs, thanks to its modular code

* **Avoid your account from banned**
  - to ensure your account is safe from being banned, we have made special guide you must follow
  - this information only for VIP users, Why? offcourse to avoid m**nt0n detection

## Main Features

![screenshot](https://raw.githubusercontent.com/anggorodhanumurti/themaphack/refs/heads/main/images/complete-esp.gif)

* Responsive maphack
  - once it activated it will adjust your phone screen automatically
* Complete ESP
  - enemy health, line, box, monster hero icon, what else you name it we got it

## Build

_This tutorial explain how to build ```Themaphack``` using ```ndk-build``` system and ```Termux``` as a terminal emulator to run compile script from Android phone_

### Prepare
We have set up custom [ndk-build](https://github.com/anggorodhanumurti/themaphack/releases/tag/ndk_aide_latest) to work on this project or you can download Android ndk at its [official website](https://developer.android.com/ndk/downloads)
- Download our custom [ndk-build](https://github.com/anggorodhanumurti/themaphack/releases/tag/ndk_aide_latest) tools
- Install [Termux](https://termux.dev/en/) on your Android devices or just use your ```terminal/cmd``` if you build on PC

```Termux
# Update repository Termux
$ pkg update && pkg upgrade -y

# Install required tools
$ pkg install git openssh wget

# Change to Termux $HOME directory
$ cd ~/

# Download ndk-build system
$ wget https://github.com/anggorodhanumurti/themaphack/releases/download/ndk_aide_latest/ndk-build.tar.gz

# Extract ndk-build
$ tar -xvzf ndk-build.tar.gz

# Clone themaphack repository
$ git clone https://github.com/anggorodhanumurti/themaphack.git && cd themaphack

# Run compile script
$ ./compile.sh
```
> **Note**
> After compile script runs successfully, the outcome is an android shared library (*.so file) generated in the libs folder. Choose lib according to your android kernel version. If you're not sure you can check your phone kernel version using [64bit checker](https://play.google.com/store/apps/details?id=com.danielpolish.a64bitchecker)
- libs/arm64-v8a for 64bit
- libs/armeabi-v7a for 32bit

## Download

You can [download](https://github.com/anggorodhanumurti/themaphack/releases/tag/v1.1.2-64bit) the latest mod according to your android kernel version.
- [stable-v1.1.2-64bit](https://github.com/anggorodhanumurti/themaphack/releases/tag/v1.1.2-64bit) for 64bit
- [stable-v1.1.2-32bit](https://github.com/anggorodhanumurti/themaphack/releases/tag/v1.1.2-32bit) for 32bit

> **Note:** if you install ml from playstore it's definitely 64bit. If you're not sure you can
 check your android kernel version [here](https://play.google.com/store/apps/details?id=com.danielpolish.a64bitchecker)

## Usage
### Installation & how to get key

_I assume you're using 64bit Android_

1. [Download](https://github.com/anggorodhanumurti/themaphack/releases) latest 64bit TMH lib

2. Open [Zarchiver](https://play.google.com/store/apps/details?id=ru.zdevs.zarchiver) go to ```Android/data/com.mobile.legends/files/dragon2017/assets/comlibs/arm64-v8a``` rename original **```libAkSoundEngine.bytes```** to **```libTMH.bytes```**

3. Extract TMH lib that you've just downloaded to that mlbb folder using Zarchiver. Path to extract: ```Android/data/com.mobile.legends/files/dragon2017/assets/comlibs/arm64-v8a```

4. You must have a key before login to modmenu. Get a key [here](https://t0pgamemurah.xyz/freeKey) after you got a key, just Copy that key!

5. TMH is installed succesfully. Now open MLBB game and when mod menu appear Paste the key to Login

## FAQ

This software uses the following open source packages:

- [Electron](http://electron.atom.io/)
- [Node.js](https://nodejs.org/)
- [Marked - a markdown parser](https://github.com/chjj/marked)
- [showdown](http://showdownjs.github.io/showdown/)
- [CodeMirror](http://codemirror.net/)
- Emojis are taken from [here](https://github.com/arvida/emoji-cheat-sheet.com)
- [highlight.js](https://highlightjs.org/)

## Related

[Try Web version of Markdownify](https://notepad.js.org/markdown-editor/)

## Support

<a href="https://buymeacoffee.com/amitmerchant" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/purple_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>

<p>Or</p> 

<a href="https://www.patreon.com/amitmerchant">
	<img src="https://c5.patreon.com/external/logo/become_a_patron_button@2x.png" width="160">
</a>

## You may also like...

- [Pomolectron](https://github.com/amitmerchant1990/pomolectron) - A pomodoro app
- [Correo](https://github.com/amitmerchant1990/correo) - A menubar/taskbar Gmail App for Windows and macOS

## License

> Released under <a href="/LICENSE">GNU GPL V3</a> by <a href="https://github.com/anggorodhanumurti">@anggorodhanumurti</a>.

> Twitter [@casperspy](https://twitter.com/casperspy)