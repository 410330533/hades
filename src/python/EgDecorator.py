from datetime import datetime, date, time

def time_it(dt):
    def decorator(func):
        def wrapper(*args, **kvargs):
            return '[time_it ' + str(dt) + '] ' + func(*args, **kvargs)
        return wrapper
    return decorator

def time_it_2(dt):
    def decorator(func):
        def wrapper(world):
            return '[time_it_2 ' + str(dt) + '] ' + func(world)
        return wrapper
    return decorator

# @time_it(datetime.now())
@time_it_2(datetime.now())
def hello(world):
    return 'hello ' + world

if __name__ == '__main__':
    print(hello('jack'))