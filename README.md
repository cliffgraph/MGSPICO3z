# MGSPICO3z 
2025/09/03 harumakkin

![mgspico3-01](docs/pics/mgspico3.png)</br>**fig.1 MGSPICO3z**

## これは何？
MGSPICO3zは以前製作した[MGSPICO3](https://github.com/cliffgraph/MGSPICO3)のZ80 CPUエミュレータ部分を、Z80 CPUコア[TV80](https://github.com/hutch31/tv80)に変更したバージョンです。MGSPICO3ではRaspberryPiPico2内で、音源ドライバMGSDRVとKINROU5を自作Z80エミュレーター上で動作させ、TangNano9K内の音源チップコアにアクセスしてMGS、MuSICA の楽曲を演奏する仕組みでした。
MGSPICO3zではTangNano9K内に、Z80 CPU(TV80)を実装しMGSDRVとKINROU5による演奏を行うようになりました。RaspberryPiPico2側はSDカードから楽曲ファイルをTangNano9Kへ転送したりOLEDや操作スイッチのUI部分を担当したりするのみとなりました。~~現状、MGSPICO3zはMGSPICO3の機能を完全に移植できていません（TGFファイル、VGMファイルの再生はできません）。~~
- v3.2.0より、NDPの再生にも対応しました。
- v3.4.0より、VGM形式、TGF形式の再生に対応しました。SDカード内のディレクトリ階層にも対応しました


## 使い方
### 用意するもの
- MGSPICO3
- [MGSDRV.COM(Ver3.20)](https://gigamix.jp/mgsdrv/)
- MGS楽曲データファイル（.MGSファイル）
- [KINROU5.DRV(Ver2.00)](https://sakuramail.net/fswold/music.html#muskin)
- MuSICA楽曲データファイル（.BGMファイル）
- [NDP.BIN(Ver1.03)](https://ndp.squares.net/web/)
- NDP楽曲データファイル（.NDPファイル）
- microSD カード
- DC5V電源(センタープラス 2.1mm DCプラグ）

### 書き込みソフトウェア
- Raspberry Pi Pico 2にインストールするファイルは、dist/mgspico3z_firmware_v3.xx/mgspico3z.uf2 です
- TangNano9Kに書き込むファイルは、dist/mgspico3z_firmware_v3.xx/HALMEM.fs です

### microSD カードの準備、セットアップ
- microSDカードを用意します。（32GBの容量の物で動作確認しています、それ以外では行っていません）
- microSDカードを、FAT、もしくは、FAT32フォーマットを施します。
- microSDカードのルートディレクトリに、MGSDRV.COM、KINROU5.DRV、NDP.BINをコピーします。
- （MGSPICO3以前に必要でした、player.com、playerK.comは必要ありません）
- 鑑賞したいMGSデータファイル(.MGS)、MuSICAデータファイル(.BGM)、NDPデータファイル(.NDP)、VGMデータファイル(.VGM)、TGFデータファイル(.TGF)、もカードへコピーします（それぞれ1000ファイルまで）。これらデータファイルはディレクトリを作成してその中に格納しても構いません。
- ロングファイルネーム、漢字やひらがなには対応していません、半角英数字で8.3形式（8文字名前+3文字拡張子）で命名してください。

## 操作方法
- [MGSPICO](https://github.com/cliffgraph/MGSPICO)と同様です。が、下記が異なります。
##### ランダム再生のＯＮ／ＯＦＦ
- 演奏中に、●SWを押しながら▼を押すとランダム再生機能がＯＮされます。もう一度同じ操作を行うとＯＦＦされます。（▼と▲の同時押しは廃止されました）
##### Z80 CPU負荷の表示
- ●SWを押しながら▲を押すと、Z80 CPU負荷表示画面に切り替わります。
- 左上に表示される数字はZ80 CPUとは関係なく、OLED表示のリフレッシュレートを表しています。通常63です
- １画面分で過去約２秒間の状態をグラフ表示します。
- このグラフバーは、MGSDRV、KINROU5、NDPの一回の呼び出しにかかった時間そのものを表していて、処理時間がかかれば白い線が長く表示れます。リフレッシュレートの下の横線は、16.6msを表しています。横線を超えるバーが表示される場合は、MGSDRV、KINROU5、NDPの一回の呼び出しに16.6ms以上を要したことを示しています。
- VGM、TGF再生では画面の切り替えを行うことはできますが、内容は表示れません。
##### 設定画面(SETTING)
- ●SWを押しながら電源を入れると、設定画面に切り替わります。
- 設定画面中に●SWを"長押し"すると、設定画面を抜けて再生画面に切り替わります。
- 設定内容はmicroSDカード内にファイル（\MGSPIC3Z.DAT）として保存されます。電源ON時に読み込まれ使用されます。
- 設定内容は下記の下記の通り

##### NDPv1.04の16KBを超える曲データの再生を行うには
- mgspico3z_firmware_v3.4.1以降では、NDPの16KBを超える曲データの再生ができるようになりましたが、再生のための準備が必要です。
- #EXPAND-MEMORYヘッダが付加されて作成された曲データが対象です。この曲データをNDP MML Compiler で、"名前を付けて曲データをBSAVE形式で保存"で .NDP ファイルを生成した後、必ず"名前を付けて効果音データをBSAVE形式で保存"で.NDDファイルも生成してください。
- この .NDPファイルと.NDDファイルの名称は同じにしてください。MGSPICOシリーズはロングファイル名や漢字文字に対応していませんので、英数アルファベット最大8文字で名付けてください。例) GAME001.NDP、GAME001.NDD
- .NDPファイルと.NDDファイルをSDカードにコピーしてください。.NDDファイルが欠けるとMGSPICO3zは正しく動作しません。

|項目|選択項目|
|:-|:-|
|music|再生するデータファイル形式を指定する<br>現バージョンでは混在での再生は行えない<br>{MGS,MuSICA,NDP,VGM,TGF}|
|loop cnt|次の曲を再生するまでの、再生回数を指定する<br>0を選択すると同じ曲を再生し続ける<br>1～3を選択すると選択した回数再生が行われた後フェードアウトが起こり次の曲に再生が移る。<br>{0, 1, 2, 3}|
|auto run|電源ON後、演奏を自動的に開始する<br>ただしルートディレクトリに再生可能なデータファイルがある時のみ<br>{OFF, ON}|
|random|ランダム再生機能をONにした状態で起動する<br>{OFF, ON}|
|use.SCC| (将来機能)使用するSCCデザインを選択する<br>（現バージョンでは、IKASCC固定である。将来用）|
|harz clk|MGS,MuSICA,NDPを再生するときのZ80互換CPUの動作クロックを指定する。CPU負荷の高い楽曲データの再生時に7.16MHzを選択する<br>{3.58MHz, 7.16MHz}<br>※RaspberryPiPicoの動作クロックではない|

# LICENSEと利用に関する注意事項
1. MGSPICO3z のファームウェアとそのソースコード、回路図データおよび資料ファイルは MIT License で配布されます。ただし、MGSPICO3z は、FatFsと8x16文字フォントを使用しています。FatFs/8x16文字フォントのソースコードの扱いに関しては各々のLICENSEに従ってください。
2. 本作品は同人ハードウェア＆ソフトウェアです。本作品の設計およびソフトウェアは品質を保証していません。音源カートリッジや音響設備、その周辺機器が故障、破損したとしても自身で責任を負える方のみ本作品をご利用ください。特にハードウェアの製作を伴いますのでリスクがあります。製作の腕に自身のある方のみご利用ください。
3. 本作品の設計資料とソースコードの改変や改造、また、別の作品への利用、商用利用は自由です。ただし、1. 2.の制限を超える利用は各自でその責任と義務を負ってください。

### MGSPICO3zが組込利用しているソフトウェア(PICO-SDK以外)
- FatFs Copyright (C) 20xx, ChaN, all right reserved. http://elm-chan.org/fsw/ff/00index_e.html
- 8x16 文字フォント FONT8X16MIN.h https://github.com/askn37/OLED_SSD1306
- IKAOPLL Copyright (c) 2023, Raki. https://github.com/ika-musume/IKAOPLL
- IKASCC Copyright (c) 2023, Raki. https://github.com/ika-musume/IKASCC
- ym2149_audio Copyright (c) 2020, Matthew Hagerty. https://github.com/dnotq/ym2149_audio
- TV80 Copyright (c) 2004 Guy Hutchison. https://github.com/hutch31/tv80

### 起動時に読み込んで使用しているソフトウェア
- MGSDRV (C) Ain./Gigamix https://gigamix.jp/mgsdrv/
- 勤労５号（MuSICA互換ドライバ） (C) 1996,1997 Keiichi Kuroda / BTO(MuSICA Laboratory) All rights reserved. https://sakuramail.net/fswold/music.html#muskin
- NDP (PSG Driver for MSX) Programmed by naruto2413 https://ndp.squares.net/web/

## 修正履歴
|date|firmware|note|
|:--|:--|:--|
|2025/11/29|mgspico3z_firmware_v3.4.1|●機能追加:<br>・NDPv1.04の16KBを超えるBGMデータ再生に対応したました(最大24KB)。
|2025/09/01|mgspico3z_firmware_v3.4.0|●機能追加:<br>・VGM形式、TGF形式の楽曲データの再生に対応した。<br>(既知の問題点としてVGM/TGFのデータを再生開始時や再思中にプチノイズが混ざることあり)<br>・SDカード内のディレクトリ階層にも対応しました<br>●改善:<br>・SETTING画面の操作性を改善しました|
|2025/08/16|mgspico3z_firmware_v3.3.1|●不具合修正:<br>loop cnt を 1 に設定してあるとき２番目に再生された曲がすぐにフェードアウトしてしまう不具合を修正した|
|2025/08/13|mgspico3z_firmware_v3.3.0|●機能修正:・SDカード内のサブディレクトリに対応した<br>・SETTINGで１曲のloop回数を、無限、1、2、3の４種類から選択できるようにした<br>・SETTINGの保存ファイル名を変更した。MGSPICO.DAT　→　MGSPIC3Z.DAT<br>・そのほかリファクタリングやFPGAコードの改良<br>|
|2025/06/26|mgspico3z_firmware_v3.2.2|●機能修正:<br>・曲切替時の、フェードアウトの音量変更を音源ドライバのボリューム設定ではなく、MIX回路内で行うようにした<br>・他、軽微な修正|
|2025/05/31|mgspico3z_firmware_v3.2.1|●不具合修正:<br>NDP楽曲でループする曲を自動終了できなかったのを改善した|
|2025/05/25|mgspico3z_firmware_v3.2.0|●機能追加:<br>音源ドライバ NDPに対応しました。NDP楽曲データファイルは.NDP拡張子をつけてください|
|2025/03/26|mgspico3z_firmware_v3.1.0|●機能追加:<br>TV80のクロックを3.58MHzと7.16MHzの二つから選べるようにしました。（[●]ボタンを押しながら電源ONでセッティング画面が起動します。セッティング画面から抜けるには[●]ボタンを長押しします。）<br>●bugfix:<br>演奏が終了し次の曲を再生するときまれに再生しないことがある不具合を修正しました|
|2025/03/02|mgspico3z_firmware_v3.00|初版|

## 各MGSPICOでサポートしている楽曲データ形式
|Model|MGS|MuSICA|NDP|VGM|TGF|
|:--|:-:|:-:|:-:|:-:|:-:|
|MGSPICO|✓|✓|✓|✓|✓|
|MGSPICO 2|✓|✓|✓|✓|✓|
|MGSPICO 3|✓|✓|✓|✓|✓|
|MGSPICO 3z|✓|✓|✓|✓※|✓※|

※MGSPICO 3z のVGM/TGFの再生では、SCC+の再生には対応していません。

## 余禄
##### VGM対応
- VGMフォーマットの仕様書そのものは[VGM Specification](https://vgmrips.net/wiki/VGM_Specification)を参照させていただきました。
- また[てつーん(@tettoon)](https://twitter.com/tettoon)さんの[VGM / S98 Player for RasPi to RE Module Interface (C Language Version)](https://github.com/tettoon/)もプログラミングの参考にさせていただきました。
- ただSCCの対応方法が判らなかったため、MSXPlayがエキスポートするVGMファイルを参考に実装しました。

##### VGM/TGFの再生について
- 再生中にSDカードへのアクセスが発生するため、ノイズが混ざることがあります
- MGSPICO 3と同様の実装方法を選択しました。MGSPICO 3zではZ80互換CPU上でドライバソフトを動作させているが、VGM/TGFではMGSPICO 3以前同様、TangNano9Kはただの音源チップとして動作し、Pico側で再生を行っています。3zのコンセプトに反しているようですがここは諦め、、、

以上

