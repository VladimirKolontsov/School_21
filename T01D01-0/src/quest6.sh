touch quest6.sh

cd ai_help
sh keygen.sh

cd key
find . -type f ! -name "*.key" -exec rm -rf {} \;
cd ..
sh unifier.sh

