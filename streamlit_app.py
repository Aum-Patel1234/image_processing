import numpy as np
import sys, os

sys.path.append(os.path.abspath("core/build"))

import image_processing

print(image_processing.add(2, 4))
image_processing.show_image("img.png")
