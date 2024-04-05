import time
from functools import wraps
import random


def retry(max_attempts=3, initial_delay=1, backoff_factor=2):
    def decorator(func):
        def wrapper(*args, **kwargs):
            attempts = 0
            delay = initial_delay

            while attempts < max_attempts:
                try:
                    result = func(*args, **kwargs)
                    return result
                except Exception as e:
                    attempts += 1
                    if attempts == max_attempts:
                        raise e
                    else:
                        print(f"Retry failed attempt {attempts}: {e}")
                        time.sleep(delay)
                        delay *= backoff_factor

        return wrapper

    return decorator


@retry(max_attempts=3, initial_delay=1, backoff_factor=2)
def perform_task():
    random_value = random.randint(0, 5)
    if random_value < 3:
        print("Task successful")
        return True
    else:
        raise Exception("Task failed")


try:
    result = perform_task()
    print("Task executed successfully")
except Exception as e:
    print(f"Task failed after maximum attempts: {e}")
