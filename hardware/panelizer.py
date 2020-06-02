import argparse

class SMT(object):
    def __init__(self, name, comment, x, y, layer, rot, foot, pn):
        self.name = name
        self.comment = comment
        self.x = x
        self.y = y
        self.layer = layer
        self.rot = rot
        self.foot = foot
        self.pn = pn

    def __str__(self):
        return "{} at {},{}".format(self.name, self.x, self.y)

def main(args):
    print("Panelizing...\n")
    parts_list = []
    with open(args.parts, 'r') as fp:
        line = fp.readline() # skip first line
        line = fp.readline().split(',')
        while(line is not None and len(line) >= 8):
            parts_list += [SMT(line[0], line[5], float(line[1]), float(line[2]),
                line[3], line[4], line[6], line[7].strip())]
            line = fp.readline().split(',')

    panelized_parts_list = []
    for i in range(args.x):
        for j in range(args.y):
            for part in parts_list:
                name = "{}{}{}".format(part.name, i, j)
                x = part.x + (i * args.xsize) + (i * args.xspace)
                y = part.y + (j * args.ysize) + (j * args.yspace)
                panelized_parts_list += [SMT(name, part.comment, x, y,
                    part.layer, part.rot, part.foot, part.pn)]

    with open("{}_panelized_BOM.csv".format(args.parts[:-4]), 'w') as fp:
        fp.write("Comment,Designator,Footprint,LCSC Part\n")
        for p in panelized_parts_list:
            fp.write("{},{},{},{}\n".format(p.comment, p.name, p.foot, p.pn))

    with open("{}_panelized_CPL.csv".format(args.parts[:-4]), 'w') as fp:
        fp.write("Designator,Mid X,Mid Y,Layer,Rotation\n")
        for p in panelized_parts_list:
            fp.write("{},{},{},{},{}\n".format(p.name, p.x, p.y, p.layer, p.rot))

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Panelizer BOM and CPL')
    parser.add_argument('--parts', metavar='parts.csv', type=str, help='Parts CSV Filename')
    parser.add_argument('-x', metavar='X', type=int, help='X axis repetitions')
    parser.add_argument('--xspace', metavar='Xspace', type=float, help='X axis spacing (mm)')
    parser.add_argument('-y', metavar='Y', type=int, help='Y axis repetitions')
    parser.add_argument('--yspace', metavar='Yspace', type=float, help='Y axis spacing (mm)')
    parser.add_argument('--xsize', metavar='Xsize', type=float, help='Board X Dimension (mm)')
    parser.add_argument('--ysize', metavar='Ysize', type=float, help='Board Y Dimension (mm)')
    args = parser.parse_args()
    main(args)
