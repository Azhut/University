f=open('input.txt').read()
asciilenth=2**7
LastChar=''
Count=0
ans=''
for CurChar in f+' ':
    if CurChar==LastChar:
        Count+=1
        continue
    
    print(Count,LastChar,sep='')
    
    ans+=Count//(asciilenth+3)*f'#{(127)}{LastChar}'
    Count%=(asciilenth+3)
    if Count>3:
        ans+=f'#{(Count-4)}{LastChar}'
    else:
        ans+=LastChar*Count
    LastChar=CurChar
    Count=1
print()
print(ans)
