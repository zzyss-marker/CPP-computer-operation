from datetime import date, timedelta
from random import randint
import sys
import subprocess

# 返回一个日期字符串，该日期是 STARTDATE 之前的 N 天
def get_date_string(n, startdate):
    d = startdate - timedelta(days=n)
    # 注意时区格式，根据需要自行调整
    rtn = d.strftime("%a %b %d %X %Y %z -0400")
    return rtn

# 主程序
def main(argv):
    if len(argv) < 1 or len(argv) > 2:
        print("错误: 输入不正确。")
        sys.exit(1)
    n = int(argv[0])
    if len(argv) == 1:
        startdate = date.today()
    if len(argv) == 2:
        startdate = date(int(argv[1][0:4]), int(argv[1][5:7]), int(argv[1][8:10]))
    i = 0
    while i <= n:
        curdate = get_date_string(i, startdate)
        num_commits = randint(1, 10)
        for commit in range(num_commits):
            # 使用单引号和双引号避免语法错误
            subprocess.call(f"echo '{curdate} {randint(0, 1000000)}' > realwork.txt; sync; git add realwork.txt; GIT_AUTHOR_DATE='{curdate}' GIT_COMMITTER_DATE='{curdate}' git commit -m 'update'", shell=True)
        i += 1
    # 移除 `-m` 开关，直接提交删除操作
    subprocess.call("git rm realwork.txt; git commit -m 'delete realwork.txt'; git push;", shell=True)

if __name__ == "__main__":
    main(sys.argv[1:])
