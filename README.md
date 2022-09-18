# Jim Player

Originally developed in 2004 as electronics gift, this project was born and grew up to powerful mediaplayer wor Windows. 

![Jim 1.1. player mode](https://github.com/wwakabobik/jim_player/blob/master/Jim_1.1/jim_1_1.png)


Of course, it's inspired by Winamp, but does not copies it. Version 2.0 was a totally redesigned rather than first versions and contains functionality to obtain data from ID3V1.1 tags from MP3 files, organize, save and load playlists and publish them as HTML. Also, player supports different languages and skins, which can be loaded, saved and updated on-the-fly by user. This is most used version of this player was supported (bugfixes and minor updates) till half of 2005. [Link to binaries](http://illusionist7.narod.ru/Jim/JimPlayer_v2.0.rar).

![Jim 2.0 interface](https://github.com/wwakabobik/jim_player/blob/master/Jim_2.0/jim.PNG)

In version 2.2, released at the end of 2005, was added several features, like extended playlist management, like hot-swap of playlists, hotkeys were added, player lose windows-like look, silent mode was added (hide to tray) with top info overlay over desktop/app windows and installer grogram. But killer-feature was addition of database engine, which help track statistic of music listening. The goal was to fast-search favourite songs, artists and albums depend on statistics, create new playlist and share them. To acheive it, app used BDE engine, which makes app less portable, than 2.0 version.

![Jim 2.2 interface and features](https://github.com/wwakabobik/jim_player/blob/master/Jim_2.2/jim_2.2.PNG)

In early 2006 version of 2.2 was introduced to my university teacher as "course project", and after some reveiew he proposed to replace BDE engine with Interbase database, which should help make app better portable. This development version should became 3.0, but after completion of "course project" I decided to switch from Interbase to MySQL engine. As result of this experiment was [Sirius Navigator](https://github.com/wwakabobik/SiriusNavigator), which was the prequisite for 3.0 version. But due to complexity of third-party DB management inside the app and poor portability this project was abandoned.

Project was developed in Borland C++ Builder 5, 6 at 2004-2007.
