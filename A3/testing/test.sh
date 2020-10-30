# db2 -f schema.txt > /dev/null
# ./bibauthor 3 > ./test/out1
# ./bibcontent 2 > ./test/out2
# ./bibcontent 3 > ./test/out3
# diff ./test/out1 ./expected/notFound.txt
# diff ./test/out2 ./expected/notFound.txt
# diff ./test/out3 ./expected/notFound.txt
#
db2 -f values.txt > /dev/null
# ./bibauthor 1 > ./test/givenBibAuthor
# ./bibcontent 3 > ./test/givenBibContent
# diff ./test/givenBibAuthor ./expected/givenBibAuthor
# diff ./test/givenBibContent ./expected/givenBibContent
#
./bibcontent 1 > ./test/bibContentNoBook
diff ./test/bibContentNoBook ./expected/bibContentNoBook
#
# db2 -f schema.txt > /dev/null
# db2 -f queries.txt > /dev/null
# ./bibcontent 2 > ./test/multipleArticles.txt
# diff ./test/multipleArticles.txt ./expected/multipleArticles.txt
# ./bibcontent 7 > ./test/nonExistent.txt
# diff ./test/nonExistent.txt ./expected/notFound.txt
#
# # multiple articles in the same publication
# ./bibauthor 5 > ./test/multiplePublications.txt
# diff ./test/multiplePublications.txt ./expected/multiplePublications
#
# ./bibauthor 20 > ./test/nonExistentAuthor.txt
# diff ./test/nonExistentAuthor.txt ./expected/notFound.txt
#
# # case https://piazza.com/class/kdj56jwd4322b3?cid=220
# ./bibauthor 21 > ./test/minorsort.txt
# diff ./test/minorsort.txt ./expected/minorsort.txt

