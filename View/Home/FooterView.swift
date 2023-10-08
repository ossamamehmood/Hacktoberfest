//
//  Created by Robert Petras
//  SwiftUI Masterclass ♥ Better Apps. Less Code.
//  https://swiftuimasterclass.com 
//

import SwiftUI

struct FooterView: View {
  var body: some View {
    VStack(alignment: .center, spacing: 10) {
        Text("Growth IT LIKE A BOSS\n Anybody can grow a beard but not everybody can be a Beardo." .uppercased())
        .foregroundColor(.gray)
        .multilineTextAlignment(.center)
        .layoutPriority(2)
        Spacer()
      Image("logo-lineal")
           
        .foregroundColor(.gray)
        .layoutPriority(0)
        Spacer()
      Text("Copyright © Beardo India\nAll right reserved")
        .font(.footnote)
        .fontWeight(.bold)
        .foregroundColor(.gray)
        .multilineTextAlignment(.center)
        .layoutPriority(1)
    } //: VSTACK
    .padding()
  }
}

struct FooterView_Previews: PreviewProvider {
  static var previews: some View {
    FooterView()
      .previewLayout(.sizeThatFits)
      .background(colorBackground)
  }
}
