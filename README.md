# gs_gset

## Desc
This lib provides a useful getter-setter functions' set.

## Functions
- ```unsigned char  gs_ft_assign(unsigned char nmemb)```
- ```unsigned char  gs_ft_set(uintptr_t var, char *name)```
- ```uintptr_t  gs_ft_get(char *name)```

## gs_ft_assign()
This must the **first** and the **last** function called in the set.
It can allocates up to 255 places (I do not think you will ever reach this limit though).
It will return 0 if something failed or nmemb if it worked.
`gs_ft_assign(13)` will allocate 13 places for the getter-setter to work (trying to set 14 variables will break your code).
`gs_ft_assign(0)` will free and nullify everything (if called first, won't do anything).

## gs_ft_set()
This function must be used after having assigned a valid number of places (1-255).
It sets up a variable known as the given name.
It may change variables but should not be used more nmemb times.
It will maybe need a bit of casting.
`gs_ft_set((uintptr_t)&var, "var1")` shouldn't be used after `gs_ft_assign(0)`.
`gs_ft_set(NULL, "var1")` or `gs_ft_set((uintptr_t)&var, NULL)` won't work.
`gs_ft_set(a, "var11")` will overwrite `gs_ft_set(b, "var11")`.

## gs_ft_get()
This function will return a variable known as the given name or 0 if nothing has been set up or the name isn't valid (unregistered or NULL).
So it wouldn't return anything else than 0 if nothing has been set up.
You will need to cast again to get back your (type)var.
`(t_chlist *)gs_ft_get("head")` will convert the list stored thanks to `gs_ft_set((uintptr_t)chained_list, "head")` into the desired type.

## Logic
This library uses a static variable system to store a `(uintptr_t)` (just a simple integer).
As it is ONLY storing integers (since memory is just a bunch of integers), the functions' set offers a universal getter-setter.
It allows to store `(t_types)`, `(char **)`, `(void *)`, `(int)`, `(unsigned long *)`... Everything.

## How To Use
```
/* -|SETTING UP|- */
|------------------------------------------------------------------------------------------------------------------------------|
if (!gs_ft_assign(2)) // Assign 2 places (Handle potential malloc fails)
  return (-1);

if (!gs_ft_set((uintptr_t)&a, "struct1") || !gs_ft_set(my_ptr, "ptr1")) // Set variables (Handle potential malloc fails)
  return (-1);
|------------------------------------------------------------------------------------------------------------------------------|


/* -|GETTING|- */
|------------------------------------------------------------------------------------------------------------------------------|
random_varname = (void *)gs_ft_get("ptr1"); // Get a pointer (No fail possible)

random_varname1 = (t_cool_struct *)gs_ft_get("ptr1"); // Casting may break the code if it wasn't set up as a (t_cool_struct *)

random_varname2 = *(t_type_of_a *)gs_ft_get("struct1"); // Get a struct (No fail possible)

random_varname3 = (t_type_of_a *)gs_ft_get("struct1"); // Get a pointer of struct (No fail possible)

zero = gs_ft_get("unregistered") // Getting 0 (No fail possible)
|------------------------------------------------------------------------------------------------------------------------------|


/* -|RESETTING|- */
|------------------------------------------------------------------------------------------------------------------------------|
gs_ft_set(new_var, "ptr1"); // Assign another variable known as "ptr1" (No fail possible)

if (!gs_ft_assign(8)) // Reset allocated places (Used to change the number of allocated places) (Handle potential malloc fails)
  return (-1);
|------------------------------------------------------------------------------------------------------------------------------|


/* -|TERMINATING|- */
|------------------------------------------------------------------------------------------------------------------------------|
gs_ft_assign(0); // No fail possible
|------------------------------------------------------------------------------------------------------------------------------|
```
