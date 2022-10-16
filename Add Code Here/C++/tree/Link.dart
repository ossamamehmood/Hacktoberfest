Link(

                        target: LinkTarget.blank,

                        uri: Uri.parse(widget.postArtLink),

                        builder: (context, followLink) {

                          return ElevatedButton(

                              onPressed: followLink,

                              child: Text("View Art  /  Download"));

                        })
