### ここは情報工の蟻本読み会のGithubリポジトリです。

[蟻本へのリンク](http://www.amazon.co.jp/dp/4839941068/)

各chapterに合わせて問題のディレクトリを作成し、その下に各々の解答を置いていきます
  
ディレクトリやファイル名の命名規則は全部スネークで統一しています。

*** 

### ディレクトリ構成

`ant_book`/`chapter`/`problem`/`user_name`/answer.cpp

 * ant_book - ルートディレクトリ

 * charpter - 章ごとのディレクトリ

 * problem - 章ごとに用意されている問題

 * user_name - 解く人の名前

#### 例
`siman` が `chapter2-1` の `ball問題` を解いた場合

`ant_book/chapter2-1/ball/siman/answer.cpp`

tree構造的には
```
ant_book
├── chapter2-1
│   ├── ball
│   │   └── siman
│   │       ├── answer.cpp
```

***

### 現在の流れ
 
#### 1. 各自課題を与えて勉強会までに各々解答してPull Requestを送る。

#### 2. 勉強会では、送られてきたPull Requestのレビューをしつつアルゴリズムの確認

 
 <br />
 <br />
まだ色々ルールを取り決めている最中なので、規約が決まり次第README.mdを更新したいと思います。
