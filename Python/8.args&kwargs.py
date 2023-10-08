def function_name(*args, **kwargs):
    for item in args:
        print(item)

    for key, value in kwargs.items():
        print(f"My name is {key}, and my number is {value}")


har = ["Ram", "Ramu", "Shamu", "Dhamu"]
rah = {"Ram": 1, "Ramu": 2, "Shamu": 3, "Dhamu": 4}

function_name(*har, **rah)
