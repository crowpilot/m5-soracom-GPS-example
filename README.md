# m5-soracom-GPS-example
soracom 3G moduleでGPSが使えるか確認する

soracomのサンプルで使用されているTinyGMSに位置情報取得の関数がある。

getGPSraw()で取得すると、まずGPSでの位置取得を試行。取得できなかった場合は携帯電波から位置を推測して返す。

soracomのボードはUBLOX SARA-U201
データシート上GPSあり
