# libarith 関数リファレンス

## 目次
1. [データ型](#データ型)
   - [t_vec3](#t_vec3)
   - [t_coord3](#t_coord3)
   - [t_quat](#t_quat)
2. [クォータニオン関数](#クォータニオン関数)
   - [quat_normalize](#quat_normalize)
   - [quat_multiply](#quat_multiply)
   - [quat_conjugate](#quat_conjugate)
   - [quat_rotate](#quat_rotate)
   - [quat_axis_angle](#quat_axis_angle)
   - [quat_from_to](#quat_from_to)
3. [ベクトル関数](#ベクトル関数)
   - [vec3_normalize](#vec3_normalize)
   - [vec3_dot](#vec3_dot)
   - [vec3_cross](#vec3_cross)
   - [vec3_add](#vec3_add)
   - [vec3_sub](#vec3_sub)
4. [座標関数](#座標関数)
   - [coord_add](#coord_add)
   - [coord_sub](#coord_sub)
5. [変換関数](#変換関数)
   - [coord_to_vec3](#coord_to_vec3)
   - [vec3_to_coord](#vec3_to_coord)
6. [高速数学関数](#高速数学関数)
   - [q_rsqrtf](#q_rsqrtf)

---

## データ型

### t_vec3
3次元ベクトルを表現する構造体です。

```c
typedef struct s_vecter3
{
    float   x;
    float   y;
    float   z;
}   t_vec3;
```

### t_coord3
3次元座標を表現する構造体です。

```c
typedef struct s_coordinates3
{
    float   x;
    float   y;
    float   z;
}   t_coord3;
```

### t_quat
クォータニオン（四元数）を表現する構造体です。回転を表現するのに使用されます。

```c
typedef struct s_quaternion
{
    float   x;
    float   y;
    float   z;
    float   w;
}   t_quat;
```

## クォータニオン関数

### quat_normalize
```c
t_quat quat_normalize(t_quat q);
```
クォータニオンを正規化します。

**パラメータ**:
- `q`: 正規化するクォータニオン

**戻り値**:
- 正規化されたクォータニオン

---

### quat_multiply
```c
t_quat quat_multiply(t_quat q1, t_quat q2);
```
2つのクォータニオンの積を計算します。

**パラメータ**:
- `q1`: 第1クォータニオン
- `q2`: 第2クォータニオン

**戻り値**:
- クォータニオンの積

---

### quat_conjugate
```c
t_quat quat_conjugate(const t_quat q);
```
クォータニオンの共役を取ります。

**パラメータ**:
- `q`: 共役を取るクォータニオン

**戻り値**:
- 共役クォータニオン

---

### quat_rotate
```c
t_quat quat_rotate(t_quat src, t_quat rot);
```
クォータニオンを使用して3Dベクトルを回転させます。

**パラメータ**:
- `src`: 回転させるベクトルを表すクォータニオン（wは0、vがベクトル）
- `rot`: 回転を表すクォータニオン

**戻り値**:
- 回転後のベクトルを表すクォータニオン

---

### quat_axis_angle
```c
t_quat quat_axis_angle(t_vec3 v, float angle);
```
軸と角度からクォータニオンを生成します。

**パラメータ**:
- `v`: 回転軸ベクトル
- `angle`: 回転角度（ラジアン）

**戻り値**:
- 指定された回転を表すクォータニオン

---

### quat_from_to
```c
t_quat quat_from_to(t_vec3 from, t_vec3 to);
```
2つの方向ベクトルからクォータニオンを生成します。

**パラメータ**:
- `from`: 元の方向ベクトル
- `to`: 目的の方向ベクトル

**戻り値**:
- 2つのベクトル間の回転を表すクォータニオン

## ベクトル関数

### vec3_normalize
```c
t_vec3 vec3_normalize(t_vec3 v);
```
ベクトルを正規化します。

**パラメータ**:
- `v`: 正規化するベクトル

**戻り値**:
- 正規化されたベクトル

---

### vec3_dot
```c
float vec3_dot(t_vec3 v1, t_vec3 v2);
```
2つのベクトルの内積を計算します。

**パラメータ**:
- `v1`: 第1ベクトル
- `v2`: 第2ベクトル

**戻り値**:
- 2つのベクトルの内積

---

### vec3_cross
```c
t_vec3 vec3_cross(t_vec3 v1, t_vec3 v2);
```
2つのベクトルの外積を計算します。

**パラメータ**:
- `v1`: 第1ベクトル
- `v2`: 第2ベクトル

**戻り値**:
- 2つのベクトルの外積

---

### vec3_add
```c
t_vec3 vec3_add(t_vec3 v1, t_vec3 v2);
```
2つのベクトルを加算します。

**パラメータ**:
- `v1`: 第1ベクトル
- `v2`: 第2ベクトル

**戻り値**:
- 2つのベクトルの和

---

### vec3_sub
```c
t_vec3 vec3_sub(t_vec3 v1, t_vec3 v2);
```
第1ベクトルから第2ベクトルを減算します。

**パラメータ**:
- `v1`: 第1ベクトル（被減数）
- `v2`: 第2ベクトル（減数）

**戻り値**:
- 2つのベクトルの差（v1 - v2）

## 座標関数

### coord_add
```c
t_coord3 coord_add(t_coord3 c1, t_coord3 c2);
```
2つの座標を加算します。

**パラメータ**:
- `c1`: 第1座標
- `c2`: 第2座標

**戻り値**:
- 2つの座標の和

---

### coord_sub
```c
t_coord3 coord_sub(t_coord3 c1, t_coord3 c2);
```
第1座標から第2座標を減算します。

**パラメータ**:
- `c1`: 第1座標（被減数）
- `c2`: 第2座標（減数）

**戻り値**:
- 2つの座標の差（c1 - c2）

## 変換関数

### coord_to_vec3
```c
t_vec3 coord_to_vec3(t_coord3 coord);
```
座標をベクトルに変換します。

**パラメータ**:
- `coord`: 変換する座標

**戻り値**:
- 変換されたベクトル

---

### vec3_to_coord
```c
t_coord3 vec3_to_coord(t_vec3 vec);
```
ベクトルを座標に変換します。

**パラメータ**:
- `vec`: 変換するベクトル

**戻り値**:
- 変換された座標

## 高速数学関数

### q_rsqrtf
```c
float q_rsqrtf(float number);
```
高速逆平方根を計算します。通常の `1/sqrt(x)` より高速ですが、若干精度が落ちます。

**パラメータ**:
- `number`: 逆平方根を計算する正の浮動小数点数

**戻り値**:
- `number`の逆平方根（`1/sqrt(number)`）の近似値