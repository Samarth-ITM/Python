class Org:
    def __init__(self, fn, tis):
        self.fn = fn
        self.tis = tis

class Bones:
    def __init__(self, stru):
        self.stru = stru
        pass

class Body:
    def __init__(self, brain, tissue, bld, bone):
        self.brain = brain
        self.tissue = tissue
        self.organ = Org(brain, tissue)
        self.bld = bld
        self.bone = [Bones(i + 1) for i in range(bone)]
        self.bones = (bone)
        
        
    def show(self):
        print(f"Your body has {self.brain} brains, {self.tissue} tissues, {self.bld} type blood, {self.bones} bones")
        
sam = Body(2, 20, "A+", 4)
        
sam.show()
