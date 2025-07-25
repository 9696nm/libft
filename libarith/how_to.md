# libarith 関数リファレンス

## 目次
1. [データ型](#データ型)
   - [t_vec3](#t_vec3)
   - [t_quater](#t_quater)
2. [クォータニオン関数](#クォータニオン関数)
   - [quater_normalize](#quater_normalize)
   - [quater_multiply](#quater_multiply)
   - [quater_conjugate](#quater_conjugate)
   - [quater_rotate](#quater_rotate)
   - [quater_axis_angle](#quater_axis_angle)
3. [高速数学関数](#高速数学関数)
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

### t_quater
クォータニオン（四元数）を表現する構造体です。回転を表現するのに使用されます。

```c
typedef struct s_quaternion
{
    float   w;
    t_vec3  v;
}   t_quater;
```

## クォータニオン関数

### quater_normalize
```c
t_quater quater_normalize(t_quater q);
```
クォータニオンを正規化します。

**パラメータ**:
- `q`: 正規化するクォータニオン

**戻り値**:
- 正規化されたクォータニオン

---

### quater_multiply
```c
t_quater quater_multiply(t_quater q1, t_quater q2);
```
2つのクォータニオンの積を計算します。

**パラメータ**:
- `q1`: 第1クォータニオン
- `q2`: 第2クォータニオン

**戻り値**:
- クォータニオンの積

---

### quater_conjugate
```c
t_quater quater_conjugate(const t_quater q);
```
クォータニオンの共役を取ります。

**パラメータ**:
- `q`: 共役を取るクォータニオン

**戻り値**:
- 共役クォータニオン

---

### quater_rotate
```c
t_quater quater_rotate(t_quater qv, t_quater p);
```
クォータニオンを使用して3Dベクトルを回転させます。

**パラメータ**:
- `qv`: 回転を表すクォータニオン
- `p`: 回転させるベクトルを表すクォータニオン（wは0、vがベクトル）

**戻り値**:
- 回転後のベクトルを表すクォータニオン

---

### quater_axis_angle
```c
t_quater quater_axis_angle(float x, float y, float z, float angle);
```
軸と角度からクォータニオンを生成します。

**パラメータ**:
- `x`, `y`, `z`: 回転軸ベクトルの成分
- `angle`: 回転角度（ラジアン）

**戻り値**:
- 指定された回転を表すクォータニオン

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

