from datetime import date, timedelta
from random import randint
import sys
import subprocess

def get_date_string(n, startdate):
    d = startdate - timedelta(days=n)
    rtn = d.strftime("%Y-%m-%d")
    return rtn

def main(argv):
    if len(argv) < 1 or len(argv) > 2:
        print("错误: 输入不正确。")
        sys.exit(1)
    n = int(argv[0])
    if len(argv) == 1:
        startdate = date.today()
    elif len(argv) == 2:
        startdate = date(int(argv[1][0:4]), int(argv[1][5:7]), int(argv[1][8:10]))

    for i in range(n + 1):
        curdate = get_date_string(i, startdate)
        num_commits = randint(1, 10)
        for _ in range(num_commits):
            with open("realwork.txt", "w") as file:
                file.write(f"{curdate} {randint(0, 1000000)}")
            subprocess.call(["git", "add", "realwork.txt"])
            subprocess.call(["git", "commit", "-m", "update", "--date", curdate])
    
    subprocess.call(["git", "rm", "realwork.txt"])
    subprocess.call(["git", "commit", "-m", "delete realwork.txt"])
    subprocess.call(["git", "push"])

if __name__ == "__main__":
    main(sys.argv[1:])
