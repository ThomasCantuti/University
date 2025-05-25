# Some useful python knowledge

## Doctest
String at the beginning of a function that test functions
```python
def uses_any(word, letters):
    """
    Check if a word uses any of a list of letters

    >>> uses_any('banana', 'aeiou')
    True
    >>> uses_any('apple', 'xyz')
    False
    """
    for letter in word.lower():
        if letter in letters.lower():
            return True
    return False

if __name__ == "__main__":
    import doctest
    doctest.testmod()
```

Each test consists of two lines:
1. The first line is the function call with the arguments
2. The second line is the expected output

Example:
```python
>>> uses_any('banana', 'xyz')
False
```

How to run:
```bash
python3 <filename>.py -v
```

## Argument packing
Collecting multiple arguments into a tuple

```python
>>> def mean(*args):
    ... return sum(args) / len(args)
    ...
>>> mean(1, 2)
1.5
>>> mean(1, 2, 3, 4, 5)
3.0
```

Parameters that begins with the * operator packs

```python
>>> t = (10, 3)
>>> divmod(*t)
(3, 1)
```

Arguments that begins with the * operator unpacks

> **NOTE:** 
> - **Parameters** are the variables defined in a function's declaration (what the function expects). In the packing example, `*args` is a parameter.
> - **Arguments** are the actual values passed to a function when calling it. In the unpacking example, `*t` provides arguments to the `divmod` function.