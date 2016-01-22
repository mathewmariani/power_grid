# power_plant

## Naming Convention

https://github.com/nonsane/power_plant
```
m for members
c for constants/readonlys
p for pointer (and pp for pointer to pointer)
v for volatile
s for static
i for indexes and iterators
e for events

_i for integer
_f for float
_d for double
_l for long
```

Using this convention we can easily see that the variable we are sending to Foo() is a member of MyClass and that is an Integer.

```cpp
// with naming convention
void MyClass::MyFunction(void) {
	Foo(m_iSomeValue)
}

// without naming convention
void MyClass::MyFunction(void) {
	Foo(someValue)
	Foo(this->someValue)
}
```


