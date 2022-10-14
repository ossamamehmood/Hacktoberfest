/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    var v1 = version1.split('.');
    var v2 = version2.split('.');
    var len = Math.max(v1.length, v2.length);

    for (var i = 0; i < len; i++) {
        var num1 = v1[i] ? Number(v1[i]) : 0;
        var num2 = v2[i] ? Number(v2[i]) : 0;

        if (num1 > num2) {
            return 1;
        } else if (num1 < num2) {
            return -1;
        }
    }

    return 0;
};