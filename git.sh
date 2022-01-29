now=$(date)
git status
git add .
git commit -m " updated on $now"
git push origin main
