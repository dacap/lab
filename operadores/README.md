# operadores

Un lenguaje que nos permite sobrecargar los operadores (como C++) nos
permite simular que nuestros tipos de datos pueden parecerse a los
tipos de datos built-in (integrados en el compilador, como *int*,
*float*, etc.).

Por ejemplo:

```c++
C = A + B;
```

Puede significar infinidad de cosas dependiendo de qué tipo de dato es
`A` y `B`. En un lenguaje como C podríamos hacer:

```c++
sumar_a_mas_b_dejar_resultado_en_c(A, B, &C);
```

En C++ podríamos hacer:

```c++
int main() {
  T A, B, C;
  C = A.sumar_a_mas_b(B);
}
```

Para una definición de `T` como:

```c++
struct T {
  T sumar_a_mas_b(const T& B) const {
    const T& A = *this;
    T C;
    // ...calcular C desde A + B...
    return C;
  }
};
```

Como C++ permite sobrecargar operadores, podemos reemplazar el nombre
`sumar_a_mas_b` con el nombre `operator+`

```c++
struct T {
  T operator+(const T& B) const {
    const T& A = *this;
    T C;
    // ...calcular C desde A + B...
    return C;
  }
};
```

Y el resultado es que ahora, en vez de llamar `A.sumar_a_mas_b(B);`
podemos hacer esto:

```c++
  C = A.operator+(B);
```

O lo que es aún más sencillo:

```c++
  C = A + B;   // llamará a "A.operator+(B)"
```

Lo importante es acordarse de la "signature" de la función miembro
`operator+`:

    T operator+(const T& B) const;

Devuelve un nuevo `T`, recibe siempre el segundo operador como `const
T&`, y el `this` es siempre `const`. Ambos operandos son `const` ya
que en una suma no los modificamos, sino que sólo los leemos para
generar un tercer valor, el resultado.

Algunos operadores comunes:

```c++
struct {
  T operator+(const T& b) const { return T(...); }
  T operator-(const T& b) const { return T(...); }
  T operator*(const T& b) const { return T(...); }
  T operator/(const T& b) const { return T(...); }
  T operator&(const T& b) const { return T(...); }
  T operator|(const T& b) const { return T(...); }
  T operator^(const T& b) const { return T(...); }
  T& operator+=(const T& b) { ... return *this; }
  T& operator-=(const T& b) { ... return *this; }
  T& operator*=(const T& b) { ... return *this; }
  T& operator/=(const T& b) { ... return *this; }
};
```
