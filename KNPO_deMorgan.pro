TEMPLATE = subdirs

CONFIG (debug, debug|release){
    CONFIGURATION = debug
    SUBDIRS += \
        Test_deMorganAndNegationsTransformations \
        Test_isCorrectNode \
        Test_makeConjunctiveDisjunctiveForm \
        Test_makeDeMorganExpressionOfNegations \
        deMorgan
} else {
    CONFIGURATION = release
    SUBDIRS += \
        deMorgan
}
