import unittest
from playfair_cipher import playfair_enc, playfair_dec


class TestPlayfairCipherMethods(unittest.TestCase):
    s = "man the wolf plugin for python in vscode is so cool"
    k = "yeahbro"
    enc_res = ['kb', 'pn', 'ba', 'vc', 'md', 'si', 'yn', 'gp', 'rc', 'on', 'bn', 'ed', 'pg', 'pu', 'qd', 'cf', 'op', 'xh', 'pd', 'dc', 'di']
    dec_res = ['ma', 'nt', 'he', 'wo', 'lf', 'pl', 'ug', 'in', 'fo', 'rp', 'yt', 'ho', 'ni', 'nv', 'sc', 'od', 'ei', 'sx', 'so', 'co', 'ol']
    def test_playfair_enc(self):
        self.assertEqual(playfair_enc(self.k, self.s), self.enc_res)

    def test_playfair_dec(self):
        self.assertEqual(playfair_dec(self.k, self.enc_res), self.dec_res)

if __name__ == '__main__':
    unittest.main()
