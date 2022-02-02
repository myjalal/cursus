now=$(date)
git status
git add .
git status
git commit -m " updated on $now"
git push origin main
